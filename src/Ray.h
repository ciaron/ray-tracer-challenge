#ifndef RAY_H
#define RAY_H

#include "Point.h"
#include "Vector.h"

class Ray {

private:
  Point _origin;
  Vector _direction;

public:

  Ray(Point origin, Vector direction) : _origin{origin}, _direction{direction} {}
  Point origin() { return _origin; }
  Vector direction() { return _direction; }
  Point position(float t) {
    //return (_origin + static_cast<Point>(_direction * t));
    return (_origin + (_direction * t));
  }
};

#endif
