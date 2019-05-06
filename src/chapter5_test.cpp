#define BOOST_TEST_MODULE Chapter5 Tests
#define BOOST_TEST_DYN_LINK
#define _USE_MATH_DEFINES

#include <boost/test/unit_test.hpp>
#include "Ray.h"
#include "Point.h"
#include "Vector.h"

using namespace std;

BOOST_AUTO_TEST_CASE( rays1 )
{
  Point origin(1,2,3);
  Vector direction(4,5,6);
  Ray r(origin, direction);

  //cout << typeid(origin).name(); //Point

  BOOST_TEST(r.origin() == origin);
  BOOST_TEST(r.direction() == direction);
}
