#ifndef VECTOR_H
#define VECTOR_H

#include "Tuple.h"

#include <cmath>

class Vector : public Tuple {
public:
  Vector(float x, float y, float z) :Tuple(x,y,z,0.0) {}

  void normalize() {
    float m = this->magnitude();
    xval /= m;
    yval /= m;
    zval /= m;
    wval /= m;
  }

  float magnitude(){
    return sqrt(xval*xval + yval*yval + zval*zval + wval*wval);
  }

  // scale a vector
  Vector operator*(const float d) const {
    return Vector(this->x()*d,this->y()*d, this->z()*d);
  }

  Vector operator*=(const float d) {
    xval *= d;
    yval *= d;
    zval *= d;
    wval *= d;
    return *this;
  }

  Vector operator+(Vector b){
      return Vector( this->x() + b.x(), this->y() + b.y(), this->z() + b.z());
  }

  Vector operator-(Vector b){
      return Vector( this->x() - b.x(), this->y() - b.y(), this->z() - b.z());
  }

  Vector reflect(const Vector& normal) {
    Vector v = *this - normal * 2 * this->dot(normal);
    return v;
  }
};


#endif
