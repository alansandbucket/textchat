#include <iostream>
#include <string>
#include "headers/ConnInfoStruct.h"

void* mainThreadFunc(void* vinfo)
{
    ConnInfo* info = (ConnInfo*)vinfo;

    std::cout << "Hello!" << std::endl;

    return NULL;
}