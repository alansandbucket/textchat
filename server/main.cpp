#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

#include "headers/Server.h"
#include "headers/ThreadFuncs.h"
#include "headers/ConnInfoStruct.h"
//#include "headers/Chatroom.h"

//Chatroom maincr; //main chatroom
Server srvr; //handles connections

int main(int argc, char* argv[])
{
    srvr = Server();
    srvr.createSocket(std::string(argv[1]));
    srvr.handleConnections();

    return 0;
}