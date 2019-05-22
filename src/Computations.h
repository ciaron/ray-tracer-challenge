#ifndef COMPUTATIONS_H
#define COMPUTATIONS_H

#include "Point.h"
#include "Vector.h"
#include "Shape.h"
#include "Intersection.h"

struct Computations {
  double t;
  Sphere object;
  Point point;
  Vector eyev;
  Vector normalv;
  bool inside = false;
};

Computations prepare_computations(const Intersection& i, const Ray& r) {

  Computations comps;
  comps.t = i.t();
  comps.object = i.object();

  //cout << "comps.object: " << &comps.object.material << endl;

  comps.point = r.position(comps.t);
  comps.eyev = -r.direction();
  comps.normalv = comps.object.normal_at(comps.point);

  if (comps.normalv.dot(comps.eyev) < 0) {
    comps.inside = true;
    comps.normalv = -comps.normalv;
  } else {
    comps.inside = false;
  }

  return comps;
}

Color shade_hit(const World& world, const Computations& comps) {
  return lighting(comps.object.material, world.light(), comps.point, comps.eyev, comps.normalv);
}

Color color_at(const World& world, const Ray& ray) {
  auto xs = world.intersect(ray);
  auto h = hit(xs); // hit() returns a shared_ptr<Intersection>

  //if (h) {cout << *h << endl; } else { cout << "miss" << endl;}

  if (!h) {
    return Color(0,0,0);
  } else {
    Computations comps = prepare_computations(*h, ray);
    return shade_hit(world, comps);
  }
}

ostream& operator<<(ostream& os, const Computations& rhs) {
    os << "Computations: " << rhs.t << " ";
    return os;
}

#endif
