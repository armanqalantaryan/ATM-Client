//
// Created by arman on 10/29/22.
//
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/time.h>

#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H
class ClientSocket {
public:
    ClientSocket();

    void startSession();
private:
    bool sendMessage (const int&);
    bool  receiveMessage();
    void connectSocket();
    void closeSocket();

    sockaddr_in m_sendSockAddr;
    const int m_clientSd;
};
#endif //CLIENT_SOCKET_H
