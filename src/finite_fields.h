#ifndef FINITE_FIELDS
#define FINITE_FIELDS

#include <stdio.h>

uint64_t mod__division(uint64_t a, uint64_t b, uint64_t p);
uint64_t mod__inverse(uint64_t a, uint64_t p);
uint64_t mod__addition(uint64_t a, uint64_t b, uint64_t p);
uint64_t mod__subtraction(uint64_t a, uint64_t b, uint64_t p);
uint64_t mod__multiplication(uint64_t a, uint64_t b, uint64_t p);
#endif