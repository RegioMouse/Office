#pragma once
#ifndef SENDLOG_SOCKET_H
#define SENDLOG_SOCKET_H
#include <iostream>
#include <WinSock2.h>
#include "Essentials.h"

using namespace std;

class Socket
{
    protected:
        WSADATA wsaData;
        SOCKET mySocket;
        SOCKET myBackup;
        SOCKET acceptSocket;
        sockaddr_in myAddress;
    public:
        Socket();
        ~Socket();
        bool SendData( char* );
        void CloseConnection();
        void GetAndSendMessage();
};

class ClientSocket : public Socket
{
    public:
        void ConnectToServer( const char *ipAddress, int port );
};

#endif
