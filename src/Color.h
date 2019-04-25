#ifndef COLOR_H
#define COLOR_H

#include "Tuple.h"
#include <cmath>

class Color : public Tuple {
public:
  Color(float red, float green, float blue) :Tuple(red, green, blue, 0.0) {}
  float red() { return this->x(); }
  float green() { return this->y(); }
  float blue() { return this->z(); }



};

#endif
