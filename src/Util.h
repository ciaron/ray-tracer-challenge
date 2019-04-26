#ifndef UTIL_H
#define UTIL_H

#include <cstdlib>
#include <string>

#include "Point.h"
#include "Vector.h"

#define EPSILON 0.00001

inline bool equal(float a, float b) {
  if (fabs(a-b) < EPSILON)
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

// scale a vector, reverse order of arguments
// see https://stackoverflow.com/questions/29492869/multiplication-operator-overloading
inline Vector operator*(const float& d, const Vector& v) {
  return v*d;
}

// cannot put this function here, because #include'ing Canvas.h introduces circular includes.
// inline std::string canvas_to_ppm(Canvas c) {
//   return "TEST";
// }

#endif
