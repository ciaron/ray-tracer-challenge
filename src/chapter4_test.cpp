#define BOOST_TEST_MODULE Chapter4 Tests
#define BOOST_TEST_DYN_LINK
#define _USE_MATH_DEFINES

#include <boost/test/unit_test.hpp>
#include <cmath>
#include "Point.h"
#include "Vector.h"
#include "Transform.h"

using namespace std;

BOOST_AUTO_TEST_CASE( translation )
{
    Point p(-3,4,5);
    Transform t;
    t.translation(5, -3, 2);
    BOOST_TEST((t*p) == Point(2,1,7));

    auto tInv = t.inverse();
    BOOST_TEST((tInv*p)==Point(-8,7,3));

    Vector v(-3,4,5);
    BOOST_TEST((tInv*v)==v);

}

BOOST_AUTO_TEST_CASE( scaling )
{
    Point p(-4,6,8);
    Transform s;
    s.scaling(2,3,4);
    BOOST_TEST((s*p) == Point(-8,18,32));

    Vector v(-4,6,8);
    BOOST_TEST((s*v) == Vector(-8,18,32));

    auto sInv = s.inverse();
    BOOST_TEST((sInv*v) == Vector(-2,2,2));

    Transform reflect;
    reflect.scaling(-1,1,1);
    Point p1(2,3,4);
    BOOST_TEST((reflect*p1) == Point(-2,3,4));
}

BOOST_AUTO_TEST_CASE( rotation )
{
  Point p(0,1,0);
  Transform hq;
  Transform fq;
  hq.rotation_x(M_PI/4);
  fq.rotation_x(M_PI/2);

  BOOST_TEST((hq*p)==Point(0,sqrt(2)/2,sqrt(2)/2));
  BOOST_TEST((fq*p)==Point(0,0,1));

  auto hqinv = hq.inverse();
  BOOST_TEST((hqinv*p)== Point(0,sqrt(2)/2, -sqrt(2)/2));

  Point p2(0,0,1);
  Transform hq2;
  Transform fq2;
  hq2.rotation_y(M_PI/4);
  fq2.rotation_y(M_PI/2);
  BOOST_TEST((hq2*p2)==Point(sqrt(2)/2,0,sqrt(2)/2));
  BOOST_TEST((fq2*p2)==Point(1,0,0));

  Point p3(0,1,0);
  Transform hq3;
  Transform fq3;
  hq3.rotation_z(M_PI/4);
  fq3.rotation_z(M_PI/2);
  BOOST_TEST((hq3*p3)==Point(-sqrt(2)/2,sqrt(2)/2, 0));
  BOOST_TEST((fq3*p3)==Point(-1,0,0));

}
BOOST_AUTO_TEST_CASE( shear1 )
{
  Point p(2,3,4);
  Transform sh;
  sh.shearing(1,0,0,0,0,0);
  BOOST_TEST((sh*p)==Point(5,3,4));
}
BOOST_AUTO_TEST_CASE( shear2 )
{
  Point p(2,3,4);
  Transform sh;
  sh.shearing(0,1,0,0,0,0);
  BOOST_TEST((sh*p)==Point(6,3,4));
}
BOOST_AUTO_TEST_CASE( shear3 )
{
  Point p(2,3,4);
  Transform sh;
  sh.shearing(0,0,1,0,0,0);
  BOOST_TEST((sh*p)==Point(2,5,4));
}
BOOST_AUTO_TEST_CASE( shear4 )
{
  Point p(2,3,4);
  Transform sh;
  sh.shearing(0,0,0,1,0,0);
  BOOST_TEST((sh*p)==Point(2,7,4));
}
BOOST_AUTO_TEST_CASE( shear5 )
{
  Point p(2,3,4);
  Transform sh;
  sh.shearing(0,0,0,0,1,0);
  BOOST_TEST((sh*p)==Point(2,3,6));
}
BOOST_AUTO_TEST_CASE( shear6 )
{
  Point p(2,3,4);
  Transform sh;
  sh.shearing(0,0,0,0,0,1);
  BOOST_TEST((sh*p)==Point(2,3,7));
}
BOOST_AUTO_TEST_CASE( chaining_transformations )
{
}
