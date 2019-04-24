#ifndef UTIL_H
#define UTIL_H

#include <cstdlib>

#define EPSILON 0.00001

inline bool equal(float a, float b) {
  if (abs(a-b) < EPSILON)
    return true;
  else
    return false;
}

#endif
