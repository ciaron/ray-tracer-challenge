#ifndef UTIL_H
#define UTIL_H

#include "Tuple.h"

#define EPSILON 0.00001

bool equal(float a, float b) {
  if (abs(a-b) < EPSILON)
    return true;
  else
    return false;
}

Tuple point(float x, float y, float z) {
    return Tuple(x, y, z, 1.0);
}

Tuple vector(float x, float y, float z) {
    return Tuple(x, y, z, 0.0);
}

#endif
