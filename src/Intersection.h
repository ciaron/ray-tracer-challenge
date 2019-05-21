#ifndef INTERSECTION_H
#define INTERSECTION_H
#include "Sphere.h"

// An intersection encapsulates an intersection "point" (distance along ray) and the object it intersects with

class Intersection {

private:
    double _t;
    Shape _object;

public:
    Intersection() : _t{0.0}, _object{Sphere()} { }
    Intersection(const double t) : _t{t}, _object{Sphere()} { }
    Intersection(const double t, const Shape s) : _t{t}, _object{s} {    }

    bool operator==(const Intersection b) const {
        return (equal(_t, b.t()) && b.object().id()==_object.id() );
    }

    Shape object() const { return _object; }
    double t() const { return _t; }
};

/* HIT */
std::shared_ptr<Intersection> hit(const vector<Intersection>& xs) {

    if (xs.size() == 0) return nullptr;

    std::shared_ptr<Intersection> i=std::make_shared<Intersection>(10000);

    // find the element of xs with the lowest, non-negative t-value
    // TODO: add <, > operators for Intersections
    for (Intersection x : xs) {
        if ( (x.t() < i->t()) && x.t() > 0.0 ) {
            *i=x;
        }
    }
    return i;
}

// Comparator for Intersections
bool compareIntersection(Intersection i1, Intersection i2)
{
    return (i1.t() < i2.t());
}

ostream& operator<<(ostream& os, const Intersection& rhs)
{
    // simply print the matrix dimensions for now. TODO
    os << "Shape ID: " << rhs.object().id() << " ";
    return os;
}

#endif
