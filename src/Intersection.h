#ifndef INTERSECTION_H
#define INTERSECTION_H
#include "Sphere.h"

// An intersection encapsulates an intersection "point" (distance along ray) and the object it intersects with

class Intersection {

private:
    float _t;
    Shape _object;

public:
    Intersection() : _t{0.0}, _object{Sphere()} { }
    Intersection(const float t) : _t{t}, _object{Sphere()} { }
    Intersection(const float t, const Shape s) : _t{t}, _object{s} {    }

    bool operator==(const Intersection b) const {
        return (equal(_t, b.t()) && b.object().id()==_object.id() );
    }

    Shape object() const { return _object; }
    float t() const { return _t; }
};

/* HIT */
Intersection hit(const vector<Intersection>& xs) {
    Intersection i(10000);

    // find the element of xs with the lowest, non-negative t-value
    // TODO: add <, > operators for Intersections
    for (Intersection x : xs) {
        if ( (x.t() < i.t()) && x.t() > 0.0 ) {
            i=x;
        }
    }
    return i;
}

ostream& operator<<(ostream& os, const Intersection& rhs)
{
    // simply print the matrix dimensions for now. TODO
    os << "Shape ID: " << rhs.object().id() << " ";
    return os;
}

#endif
