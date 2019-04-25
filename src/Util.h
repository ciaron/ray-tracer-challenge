#ifndef UTIL_H
#define UTIL_H

#include "Point.h"
#include "Vector.h"
#include <cstdlib>

#define EPSILON 0.00001

inline bool equal(float a, float b) {
  if (abs(a-b) < EPSILON)
    return true;
  else
    return false;
}

// Add a point and a vector
inline Point operator+(const Point& p, const Vector& v){
  Point p2{ p.x() + v.x(), p.y() + v.y(), p.z() + v.z() };
  return p2;
}

// Add a vector and a vector
inline Vector operator+(const Vector& v1, const Vector& v2){
  Vector v3{ v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z() };
  return v3;
}
#endif
