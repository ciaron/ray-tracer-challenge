#define BOOST_TEST_MODULE Chapter6 Tests
#define BOOST_TEST_DYN_LINK
#define _USE_MATH_DEFINES

#include <boost/test/unit_test.hpp>
#include "Util.h"
#include "Matrix.h"
#include "Ray.h"
#include "Point.h"
#include "Vector.h"
#include "Sphere.h"
#include "Intersection.h"

using namespace std;

int Shape::count=0;

BOOST_AUTO_TEST_CASE( normal_at )
{
  Sphere s;
  auto n1 = s.normal_at(Point(1,0,0));
  BOOST_TEST(n1==Vector(1,0,0));

  auto n2 = s.normal_at(Point(0,1,0));
  BOOST_TEST(n2==Vector(0,1,0));

  auto n3 = s.normal_at(Point(0,0,1));
  BOOST_TEST(n3==Vector(0,0,1));

  float p = sqrt(3.0)/3.0;
  auto n4 = s.normal_at(Point(p,p,p));
  BOOST_TEST(n4==Vector(p,p,p));

  Vector v = n4;
  v.normalize();
  BOOST_TEST(n4 == v);
  BOOST_TEST(n4 == normalize(n4)); // alternate version in Util.h
}

BOOST_AUTO_TEST_CASE (transforming_normals) {
  Sphere s;
  s.set_transform(identity().translation(0,1,0));

  Vector n = s.normal_at(Point(0, 1.70711, -0.70711));
  BOOST_TEST(n==Vector(0, 0.70711, -0.70711));

  s.set_transform(identity().scaling(1, 0.5, 1).rotation_z(M_PI/5.0));
  Vector n2 = s.normal_at(Point(0, sqrt(2)/2, -sqrt(2)/2));
  BOOST_TEST(n2==Vector(0, 0.97014, -0.24254));
}
