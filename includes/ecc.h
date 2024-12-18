#ifndef SECP256K1_H
#define SECP256K1_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint64_t x_point;
    uint64_t y_point;
    bool is_infinity;
} ecc_curves_datapoints;

ecc_curves_datapoints* point_addition(ecc_curves_datapoints* p, ecc_curves_datapoints* q);
ecc_curves_datapoints* point_doubling(ecc_curves_datapoints* p, ecc_curves_datapoints* q);
ecc_curves_datapoints* scalar_multiplication(ecc_curves_datapoints* P, uint64_t k, uint64_t q, uint64_t p);

#endif