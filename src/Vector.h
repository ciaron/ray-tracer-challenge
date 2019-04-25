#ifndef VECTOR_H
#define VECTOR_H

#include "Tuple.h"
#include <cmath>
// inline Tuple vector(float x, float y, float z) {
//     return Tuple(x, y, z, 0.0);
// }

class Vector : public Tuple {
public:
  Vector(float x, float y, float z) :Tuple(x,y,z,0.0) {}

  Vector normalize() {
    float m = this->magnitude();
    return Vector(xval/m, yval/m, zval/m);//, wval/m);
  }

  float magnitude(){
    return sqrt(xval*xval + yval*yval + zval*zval + wval*wval);
  }
};

#endif
