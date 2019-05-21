#ifndef COMPUTATIONS_H
#define COMPUTATIONS_H

#include "Shape.h"
#include "Intersection.h"

struct Computations {
  double t;
  Shape object;
  Point point;
  Vector eyev;
  Vector normalv;
};

Computations prepare_computations(const Intersection& i, const Ray& r) {
  Computations comps;
  comps.t = i.t();
  comps.object = i.object();
  comps.point = r.position(comps.t);
  comps.eyev = -r.direction();
  comps.normalv = -r.direction();

  return comps;
}

ostream& operator<<(ostream& os, const Computations& rhs) {
    os << "Computations: " << rhs.t << " ";
    return os;
}

#endif
