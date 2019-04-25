#ifndef VECTOR_H
#define VECTOR_H

#include "Tuple.h"
#include <cmath>

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


  // scale a vector
  Vector operator*(const float d){
    return Vector(this->x()*d,this->y()*d, this->z()*d);
  }
};

#endif
