#pragma once

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

#define NUM_CHAT 64

class Server
{
    public:
        Server();
        void createSocket(std::string portNumStr);
        void handleConnections();

    private:
        int pthsCount;
        std::vector<pthread_t*> pths;
        int numConnections;
        int portNum;
        int listenSocketfd;
        struct sockaddr_in servAddr;

        int addUser();
};