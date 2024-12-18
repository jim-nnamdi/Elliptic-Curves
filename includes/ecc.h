#ifndef SECP256K1_H
#define SECP256K1_H

#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint64_t x_point;
    uint64_t y_point;
    uint64_t **b_points;
} ecc_curves_datapoints;

ecc_curves_datapoints* point_addition(ecc_curves_datapoints* p, ecc_curves_datapoints* q);
ecc_curves_datapoints* point_doubling(ecc_curves_datapoints* p, ecc_curves_datapoints* q);

#endif