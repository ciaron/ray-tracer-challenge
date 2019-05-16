#ifndef LIGHT_H
#define LIGHT_H

#include "Point.h"
#include "Vector.h"
#include "Color.h"

class Pointlight {

  public:
    Point position;
    Color intensity;
    Pointlight(Point p, Color c) : position{p},intensity{c} {}

};

Color lighting(const Material& m, const Pointlight& light, const Point& position, const Vector& eyev, const Vector& normalv) {
    return Color(0,0,0);
}

#endif
