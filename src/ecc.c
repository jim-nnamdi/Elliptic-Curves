#include "includes/ecc.h"
#include "finite_fields.h"

ecc_curves_datapoints* point_addition(ecc_curves_datapoints* p, ecc_curves_datapoints* q) {
    // recall p = (x0, y0) and q = (x1, y1)
    // lambda = (y1 - y0)/(x1 - x0)
    ecc_curves_datapoints* curve_point_addition = (ecc_curves_datapoints *)malloc(sizeof(ecc_curves_datapoints));
    uint64_t lambda = mod__division((q->y_point - p->y_point),(q->x_point - p->x_point),p->b_points);
    uint64_t x3_curve = (lambda * lambda) - p->x_point - q->x_point;
    uint64_t y3_curve = (lambda * (p->x_point - x3_curve) - p->y_point);
    curve_point_addition->x_point = x3_curve; curve_point_addition->y_point = y3_curve;
    return curve_point_addition;
}

ecc_curves_datapoints* point_addition(ecc_curves_datapoints* p, ecc_curves_datapoints* q) {
    // recall p = (x0, y0) and q = (x1, y1)
    // lambda = 3xi / 2yi where p == q
    ecc_curves_datapoints* curve_point_doubling = (ecc_curves_datapoints *)malloc(sizeof(ecc_curves_datapoints));
    uint64_t lambda = mod__division(3 * p->x_point, 2 * q->y_point,p->b_points);
    uint64_t x3_curve = (lambda * lambda) - p->x_point - p->x_point;
    uint64_t y3_curve = (lambda * (p->x_point - x3_curve) - p->y_point);
    curve_point_doubling->x_point = x3_curve; curve_point_doubling->y_point = y3_curve;
    return curve_point_doubling;
}

uint64_t modular_point_addition(uint64_t x, uint64_t y, uint64_t p) {
    uint64_t modular_result = x + y;
    return (modular_result >= p ) ? modular_result - p : modular_result;
}