#include <string>
#include <iostream>

#include <cstring>
#include <cstdlib>
#include <cstdio>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "headers/Connection.h"
#include "headers/OtherFuncs.h"

Connection::Connection()
{
    conn = nullptr;
}

void Connection::createConnection(std::string ipStr, std::string portStr)
{
    int sockfd, portnum;
    struct sockaddr_in servAddr;
    struct hostent* server;

    if (sscanf(portStr.c_str(), "%d", &portnum) < 1)
        error("portStr is not a number\n", 1);
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("error opening socket\n", 1);
    
    bzero((char*)&servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(portnum);
    if (inet_pton(AF_INET, ipStr.c_str(), &servAddr.sin_addr) <= 0)
        error("Invalid address or address not supported", 1);
    
    if (connect(sockfd, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
        error("error connecting", 1);
    
    if (conn != nullptr)
        delete conn;
    
    conn = new ConnInfo;
    conn->sockfd = sockfd;
}