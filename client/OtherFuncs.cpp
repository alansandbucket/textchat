#include <iostream>
#include <cstdlib>
#include <string>
#include "headers/OtherFuncs.h"

void error(std::string msg, int exitStatus)
{
    std::cerr << msg << std::endl;
    exit(exitStatus);
}