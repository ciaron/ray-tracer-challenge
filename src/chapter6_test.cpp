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
  BOOST_TEST(n1==Vector(p,p,p));
}
