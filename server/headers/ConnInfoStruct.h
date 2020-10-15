#pragma once
#include <sys/socket.h>
#include <netinet/ip.h>


struct ConnInfo
{
    int sockfd;
    sockaddr_in cInfo;
};

typedef struct ConnInfo ConnInfo;