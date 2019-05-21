#ifndef RAY_H
#define RAY_H

#include <memory>
#include "Point.h"
#include "Vector.h"
#include "Sphere.h"
#include "Intersection.h"
#include "Matrix.h"
#include "Util.h"

class Ray {

private:
  Point _origin;
  Vector _direction;

public:

  Ray(Point origin, Vector direction) : _origin{origin}, _direction{direction} {}

  const Point origin() const { return _origin; }
  const Vector direction() const { return _direction; }

  Point position(double t) const {
    return (_origin + (_direction * t));
  }

  // intersect with a Sphere
  vector<Intersection> intersect(const Sphere& s) const {

    double t1, t2;

    // chapter 5, get transformed ray
    auto tr = this->transform(s.get_transform().inverse());

    // calculate discriminant
    //Vector sphere_to_ray = this->origin() - Point(0,0,0); // 0,0,0 is the centre of the sphere
    Vector sphere_to_ray = tr->origin() - Point(0,0,0); // 0,0,0 is the centre of the sphere

    double a = tr->direction().dot(tr->direction());
    double b = 2 * tr->direction().dot(sphere_to_ray);
    double c = sphere_to_ray.dot(sphere_to_ray) - 1.0;
    double d = b*b - 4*a*c;

    vector<Intersection> xs{};
    // get intersection points, if any
    if (d < 0) {
        return xs;
    } else {
        t1 = (-b - sqrt(d)) / (2*a);
        t2 = (-b + sqrt(d)) / (2*a);
        //return vector<Intersection> {t1,t2};
        xs.push_back(Intersection(t1, s));
        xs.push_back(Intersection(t2, s));
        return xs;
    }
  }

  // apply a transformation matrix to a ray
  std::shared_ptr<Ray> transform(const Matrix& m) const {
      // no memory leak with shared_ptr, in contrast to returning a Ray object
      return std::make_shared<Ray>(m*this->origin(), m*this->direction());
  }

};

#endif
