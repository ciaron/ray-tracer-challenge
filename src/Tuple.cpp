#include "Tuple.h"

Tuple::Tuple(float x=0.0, float y=0.0, float z=0.0, float w=0.0) {
    xval=x;	yval=y;	zval=z;	wval=w;
	}

float Tuple::x() { return xval; }
float Tuple::y() { return yval; }
float Tuple::z() { return zval; }
float Tuple::w() { return wval; }
bool Tuple::isPoint() { return true; }
