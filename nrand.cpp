#include <cmath> // ceil
#include <cstdlib> // rand
#include <stdexcept> // domain_error
#include <limits.h>

#include "nrand.h"

#define MY_RAND_MAX 32767

int nrand(int n){
    if (n <= 0)
        throw std::domain_error("Argument to nrand is out of range.");
    int r;

    if (n < MY_RAND_MAX){
        const int bucket_size = MY_RAND_MAX / n;

        do {
            int bucket = rand() / bucket_size;
            r = bucket;
        } while (r >= n);

    } else {
        const int bucket_size = std::ceil(n / MY_RAND_MAX);

        do {
            const int bucket = nrand(MY_RAND_MAX);
            const int remainder = nrand(bucket_size);
            r = (bucket - 1) * bucket_size + remainder;
        } while (r >= n);

    }

    return r;
}

