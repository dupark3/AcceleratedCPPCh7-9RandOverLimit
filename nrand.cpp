
#include <cstdlib> // rand
#include <stdexcept> // domain_error
int nrand(int n){
    if (n <= 0 || n > RAND_MAX)
        throw std::domain_error("Argument to nrand is out of range.");

    const int bucket_size = (RAND_MAX * RAND_MAX) / n;
    int r;

    do r = (rand() * rand()) / bucket_size;
    while (r >= n);

    return r;
}
