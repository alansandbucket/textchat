#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <type_traits>

#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#include "headers/Server.h"
#include "headers/OtherFuncs.h"
#include "headers/ConnInfoStruct.h"
#include "headers/ThreadFuncs.h"

Server::Server()
{
    numConnections = 64;
    bzero((char*)&servAddr, sizeof(servAddr));
    pthsCount = 0;
    pths = std::vector<pthread_t*>();
}

void Server::createSocket(std::string portNumStr)
{
    portNum = atoi(portNumStr.c_str());
    
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
    {
        int clientSockfd;
        pthread_t* pth = new pthread_t;
        struct sockaddr_in clientAddr;
        ConnInfo* ci = new ConnInfo;
        socklen_t cliLen;
        cliLen = sizeof(clientAddr);
        clientSockfd = accept(listenSocketfd, (struct sockaddr *) &clientAddr, &cliLen);
        if (clientSockfd < 0)
        {
            fprintf(stderr, "Error on accepting a connection");
            continue;
        }
        ci->sockfd = clientSockfd;
        ci->cInfo = clientAddr;

        int tr = pthread_create(pth, NULL, mainThreadFunc, (void*)ci);
        pths.push_back(pth);
        pthsCount++;
    }
}