#include <ctime> // time
#include <cstdlib> // srand
#include <iostream>

#include "nrand.h"

int main()
{
    std::srand(std::time(NULL));

    return 0;
}
