#include "finite_fields.h"
#include <stdint.h>

uint64_t mod__addition(uint64_t a, uint64_t b, uint64_t p) {
    return (a + b) % p;
}

uint64_t mod__subtraction(uint64_t a, uint64_t b, uint64_t p) {
    return (a - b + p) % p;
}

uint64_t mod__multiplication(uint64_t a, uint64_t b, uint64_t p) {
    return ( a * b) % p;
}

uint64_t mod__inverse(uint64_t a, uint64_t p) {
    uint64_t t = 0; uint64_t new_t = 1;
    uint64_t r = p; uint64_t new_r = a;

    while(new_r != 0){
        uint64_t Q = r / new_r;
        uint64_t temp_t = t;
        t = new_t;
        new_t = temp_t - Q * new_t;
 
        uint64_t temp_r = r;
        r = new_r;
        new_r = temp_r - Q * new_r;
    }

    if (r > 1) fprintf(stderr, "non invertible numbers");
    return (t < 0) ? t - p : t;
}

uint64_t mod__division(uint64_t a, uint64_t b, uint64_t p) {
    return mod__multiplication(a, mod__inverse(b, p), p);
}