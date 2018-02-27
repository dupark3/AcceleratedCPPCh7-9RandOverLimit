#include <ctime> // time
#include <cstdlib> // srand
#include <iostream>

#include "nrand.h"

int main()
{
    std::srand(std::time(NULL));
    int limit;

    while (std::cin >> limit)
        std::cout << nrand(limit) << std::endl;

    return 0;
}
