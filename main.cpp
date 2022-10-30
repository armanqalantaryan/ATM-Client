//
// Created by arman on 10/8/22.
//

#include "ClientSocket/ClientSocket.h"

//Client side
int main()
{
    ClientSocket clientSocket;
    try
    {
        clientSocket.startSession();
    }
    catch (std::runtime_error e)
    {
        std::cout << "Exited with error: ";
        std::cout << e.what() << std::endl;
    }

    return 0;
}