#include "Tuple.h"
#include "Util.h"
#include <cstdlib>

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
    return (equal(wval, 1.0)) ? true : false;
}

bool Tuple::isVector() {
    return (equal(wval, 0.0)) ? true : false;
}

bool Tuple::isEqual(Tuple t) {
    return equal(xval, t.x()) && equal(yval, t.y()) && equal(zval, t.z());
}
