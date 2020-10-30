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

class User
{
    public:
        User(std::string n, int s);
        void setUserName();
        void setSocket();
        void getName();
    private:
        std::string name;
        int sockfd;
}