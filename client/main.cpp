#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "headers/Connection.h"
#include "headers/SigHandlers.h"

Connection conn;

int main(int argc, char* argv[])
{
    std::cout << argv[0] << " ip port" << std::endl;
    setupSignalHandlers();
    conn = Connection();
    conn.createConnection(argv[1], argv[2]);

    while(true);
}