#include <cstdio>
#include <cstdlib>

void error(const char* msg, int exVal)
{
    fprintf(stderr, "%s", msg);
    exit(exVal);
}