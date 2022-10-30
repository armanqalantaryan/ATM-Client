//
// Created by arman on 10/29/22.
//
#include "ClientSocket.h"

#include <stdexcept>

namespace
{
    const char *IP_ADDRESS = "localhost";
    const int PORT = 1245;
}

ClientSocket::ClientSocket(): m_clientSd(socket(AF_INET, SOCK_STREAM, 0))
{
    const auto& host = gethostbyname(IP_ADDRESS);

    m_sendSockAddr.sin_addr.s_addr =
            inet_addr(inet_ntoa(*(struct in_addr*)*host->h_addr_list));
    m_sendSockAddr.sin_port = htons(PORT);
    m_sendSockAddr.sin_family = AF_INET;
}

bool ClientSocket::sendMessage(const int& message)
{
    return send(m_clientSd, (char *)&message, sizeof(message), 0);
}

bool ClientSocket::receiveMessage()
{
    std::cout << "Awaiting server response..." << std::endl;
    //FIXME Need to be improved
    int message;
    int status = recv(m_clientSd, (char*)&message, sizeof(message), 0);
    std::cout << message << std::endl;
    return status >= 0;
}

void ClientSocket::closeSocket()
{
    close(m_clientSd);
    std::cout << "Connection closed!" << std::endl;
}

void ClientSocket::connectSocket()
{
    int status = connect(m_clientSd,
                         (sockaddr*) &m_sendSockAddr, sizeof(m_sendSockAddr));
    if(status < 0)
    {
        throw std::runtime_error("Error connecting to the Server!");
    }
    std::cout << "Connected to the Server!" << std::endl;
}

void ClientSocket::startSession()
{
    connectSocket();

    while (true) {
        std::cout << "Enter the card number: ";
        int data;
        std::cin >> data;
        if(sendMessage(data) < 0) {
            throw std::runtime_error("Error while sending a message!");
        }

        if(receiveMessage() < 0) {
            throw std::runtime_error("Error while receiving a message!");
        }
        // FIXME Need to be improved
        if(data == 0) {
            break;
        }
    }

    closeSocket();
}