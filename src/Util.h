#ifndef UTIL_H
#define UTIL_H

#include <cstdlib>
#include <string>

#include "Point.h"
#include "Vector.h"
#define EPSILON 0.00001

inline bool equal(double a, double b) {
  return (abs(a-b) < EPSILON);
  //if (abs(a-b) < EPSILON)
  //  return true;
  //else
  //  return false;
}

// Add a point and a vector
inline Point operator+(const Point& p, const Vector& v) {
  Point p2{ p.x() + v.x(), p.y() + v.y(), p.z() + v.z() };
  return p2;
}

// subtract two points to get a vector between them
inline Vector operator-(const Point& p1, const Point& p2) {
  Vector v{ p1.x() - p2.x(), p1.y() - p2.y(), p1.z() - p2.z() };
  return v;
}

// Add a vector and a vector
inline Vector operator+(Vector& v1, Vector& v2) {
  Vector v3{ v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z() };
  return v3;
}

// scale a vector, reverse order of arguments
// see https://stackoverflow.com/questions/29492869/multiplication-operator-overloading
inline Vector operator*(const double& d, const Vector& v) {
  return v*d;
}

// return a new normalized vector
inline Vector normalize(const Vector& v) {
  Vector v2 = v;
  v2.normalize();
  return v2;
}
// cannot put this function here, because #include'ing Canvas.h introduces circular includes.
// inline std::string canvas_to_ppm(Canvas c) {
//   return "TEST";
// }

#endif
