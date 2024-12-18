#include "includes/ecc.h"

uint64_t modular_point_addition(uint64_t x, uint64_t y, uint64_t p) {
    uint64_t modular_result = x + y;
    return (modular_result >= p ) ? modular_result - p : modular_result;
}