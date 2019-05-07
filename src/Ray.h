#ifndef RAY_H
#define RAY_H

#include "Point.h"
#include "Vector.h"
#include "Sphere.h"
#include "Intersection.h"
#include "Util.h"

class Ray {

private:
  Point _origin;
  Vector _direction;

public:

  Ray(Point origin, Vector direction) : _origin{origin}, _direction{direction} {}

  const Point origin() const { return _origin; }
  const Vector direction() const { return _direction; }

  Point position(float t) {
    return (_origin + (_direction * t));
  }

  // intersect with a Sphere
  vector<float> intersect(const Sphere& s) const {

    float t1, t2;

    // calculate discriminant
    Vector sphere_to_ray = this->origin() - Point(0,0,0); // 0,0,0 is the centre of the sphere

    float a = _direction.dot(_direction);
    float b = 2 * _direction.dot(sphere_to_ray);
    float c = sphere_to_ray.dot(sphere_to_ray) - 1.0;
    float d = b*b - 4*a*c;

    // get intersection points, if any
    if (d < 0) {
        return vector<float>{};
    } else {
        t1 = (-b - sqrt(d)) / (2*a);
        t2 = (-b + sqrt(d)) / (2*a);
        return vector<float> {t1,t2};
    }
  }

  // TODO (Tracking Intersections): return vector<Intersection> {t1,Shape},{t2,Shape}

};

#endif
