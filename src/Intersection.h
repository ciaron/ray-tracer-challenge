#ifndef INTERSECTION_H
#define INTERSECTION_H
#include "Sphere.h"

// An intersection encapsulates an intersection "point" (distance along ray) and the object it intersects with

class Intersection {

private:
    float _t;
    Shape _object;

public:

    Intersection(const float t, const Shape s) : _t{t}, _object{s} {    }

    Shape object() const { return _object; }
    float t() const { return _t; }
};

#endif
