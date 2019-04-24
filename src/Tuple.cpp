#include "Tuple.h"
#include <cstdlib>

#define EPSILON 0.00001

bool isEqual(float a, float b) {
  if (abs(a-b) < EPSILON)
    return true;
  else
    return false;
}

Tuple::Tuple(float x=0.0, float y=0.0, float z=0.0, float w=0.0) {
    xval=x;
    yval=y;
    zval=z;
    wval=w;
}

float Tuple::x() { return xval; }
float Tuple::y() { return yval; }
float Tuple::z() { return zval; }
float Tuple::w() { return wval; }

bool Tuple::isPoint() {
    return (isEqual(wval, 1.0)) ? true : false;
}

bool Tuple::isVector() {
    return (isEqual(wval, 0.0)) ? true : false;
}
