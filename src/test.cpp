#define BOOST_TEST_MODULE Tuple Test
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "Tuple.h"
#include "Point.h"
#include "Vector.h"

BOOST_AUTO_TEST_CASE( constructor_test )
/* Create a new Tuple */
{
  Tuple t1(1.0, 2.0, 3.0, 1.0);
  BOOST_TEST( t1.x() == 1.0 );
}

BOOST_AUTO_TEST_CASE( is_point_or_vector )
{
  Tuple t2(4.3, -4.2, 3.1, 1.0);
  BOOST_TEST( t2.isPoint() == true );
  BOOST_TEST( t2.isVector() == false );

  Tuple t3(4.3, -4.2, 3.1, 0.0);
  BOOST_TEST( t3.isPoint() == false );
  BOOST_TEST( t3.isVector() == true );
}

BOOST_AUTO_TEST_CASE( create_point_or_vector )
{
    Tuple p = point(4, -4, 3);
    Tuple t4(4, -4, 3, 1.0);       // w=1.0, a point

    Tuple v = vector(4, -4, 3);
    Tuple t5(4.3, -4.2, 3.1, 0.0); // w=0.0, a vector

    BOOST_TEST(p.isPoint() == true);
    BOOST_TEST(p.isEqual(t4));

    BOOST_TEST(v.isVector() == true);
    BOOST_TEST(v.isEqual(t5));
}
