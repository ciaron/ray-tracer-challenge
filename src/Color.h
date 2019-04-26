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

    // add colors
    Color operator+(Color c){
        return Color( this->red() + c.red(), this->green() + c.green(), this->blue() + c.blue() );
    }

    // subtract colors
    Color operator-(Color c){
        return Color( this->red() - c.red(), this->green() - c.green(), this->blue() - c.blue() );
    }

    // multiply a color by a scalar
    Color operator*(float s){
        return Color( this->red() * s, this->green() * s, this->blue() * s );
    }

    // multiply two colors (Hadamard product)
    Color operator*(Color c){
        return Color( this->red() * c.red(), this->green() * c.green(), this->blue() * c.blue() );
    }

};

#endif
