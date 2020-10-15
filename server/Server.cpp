#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#include "headers/Server.h"
#include "headers/OtherFuncs.h"
#include "headers/ConnInfoStruct.h"

Server::Server(int numCon)
{
    numConnections = numCon;
    bzero((char*)&servAddr, sizeof(servAddr));
}

void Server::createSocket(char* portNumStr)
{
    portNum = atoi(portNumStr);
    
    if ((listenSocketfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        error("ERROR: Opening socket", 2);
    }

    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_port = htons(portNum);

    if (bind(listenSocketfd, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0)
    {
        error("ERROR: binding socket to fd", 2);
    }
}

void Server::handleConnections()
{
    listen (listenSocketfd, numConnections);

    while(true)
}