#pragma once

#include "ConnInfo.h"

class Connection
{
    private:
        ConnInfo* conn;
    public:
        Connection();
        void createConnection(std::string ipStr, std::string portStr);
        ConnInfo* getConnection();
};