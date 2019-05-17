#ifndef COLOR_H
#define COLOR_H

#include "Tuple.h"
#include "Util.h"
#include <cmath>

class Color : public Tuple {

  public:
    Color() :Tuple(0.0,0.0,0.0,0.0) {}
    Color(float red, float green, float blue) :Tuple(red, green, blue, 0.0) {}
    float red()   const { return this->x(); }
    float green() const { return this->y(); }
    float blue()  const { return this->z(); }

    // test colors for equality
    bool operator==(const Color& b) const {
        return ( equal(this->red(), b.red()) && equal(this->green(), b.green()) && equal(this->blue(), b.blue()));
    }

    // add colors
    Color operator+(Color c){
        return Color( this->red() + c.red(), this->green() + c.green(), this->blue() + c.blue() );
    }

    // subtract colors
    Color operator-(Color c){
        return Color( this->red() - c.red(), this->green() - c.green(), this->blue() - c.blue() );
    }

    // multiply a color by a scalar
    Color operator*(float s) const {
        return Color( this->red() * s, this->green() * s, this->blue() * s );
    }

    // multiply two colors (Hadamard product)
    Color operator*(Color c) const {
        return Color( this->red() * c.red(), this->green() * c.green(), this->blue() * c.blue() );
    }
};

#endif
