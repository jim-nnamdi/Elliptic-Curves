#include "includes/ecc.h"
#include "finite_fields.h"

ecc_curves_datapoints* point_addition(ecc_curves_datapoints* p, ecc_curves_datapoints* q) {
    // recall p = (x0, y0) and q = (x1, y1)
    // lambda = (y1 - y0)/(x1 - x0)
    ecc_curves_datapoints* curve_point_addition = (ecc_curves_datapoints *)malloc(sizeof(ecc_curves_datapoints));
    uint64_t lambda = mod__division((q->y_point - p->y_point),(q->x_point - p->x_point),p->x_point);
    uint64_t x3_curve = (lambda * lambda) - p->x_point - q->x_point;
    uint64_t y3_curve = (lambda * (p->x_point - x3_curve) - p->y_point);
    curve_point_addition->x_point = x3_curve; curve_point_addition->y_point = y3_curve;
    return curve_point_addition;
}

ecc_curves_datapoints* point_addition(ecc_curves_datapoints* P, ecc_curves_datapoints* Q) {
    // recall p = (x0, y0) and q = (x1, y1)
    // lambda = 3xi / 2yi where p == q
    if ((*P).is_infinity) return Q;
    if ((*Q).is_infinity) return P;
    
    ecc_curves_datapoints* curve_point_doubling = (ecc_curves_datapoints *)malloc(sizeof(ecc_curves_datapoints));
    uint64_t lambda = mod__division(3 * P->x_point, 2 * Q->y_point,P->x_point);
    uint64_t x3_curve = (lambda * lambda) - P->x_point - P->x_point;
    uint64_t y3_curve = (lambda * (P->x_point - x3_curve) - P->y_point);
    curve_point_doubling->x_point = x3_curve; curve_point_doubling->y_point = y3_curve;
    return curve_point_doubling;
}

ecc_curves_datapoints* scalar_multiplication(ecc_curves_datapoints* P, uint64_t k, uint64_t q, uint64_t p) {
    ecc_curves_datapoints *R = malloc(sizeof(ecc_curves_datapoints));
    ecc_curves_datapoints *Q = P; 
    while (k > 0){
        if (k & 1) 
            R = point_addition(R, P);
        Q = point_addition(Q,P);
        k >>= 1;
    }
    return R;
}

uint64_t modular_point_addition(uint64_t x, uint64_t y, uint64_t p) {
    uint64_t modular_result = x + y;
    return (modular_result >= p ) ? modular_result - p : modular_result;
}