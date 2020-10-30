#include <iostream>
#include <string>
#include <signal.h>
#include <unistd.h>
#include "headers/SigHandlers.h"

void setupSignalHandlers()
{
    if (signal(SIGINT, SIGINTHandler) == SIG_ERR)
        std::cout << "can't catch SIGINT\n" << std::endl;
}

void SIGINTHandler(int sig)
{
    std::cout << "caught SIGINT. " << sig << "." << std::endl;
    exit(0);
}