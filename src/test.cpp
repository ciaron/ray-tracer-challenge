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

// Chapter 1 - Tuples
BOOST_AUTO_TEST_CASE( is_point_or_vector )
{
  Tuple t2(4.3, -4.2, 3.1, 1.0);
  BOOST_TEST( t2.isPoint() == true );
  BOOST_TEST( t2.isVector() == false );

  Tuple t3(4.3, -4.2, 3.1, 0.0);
  BOOST_TEST( t3.isPoint() == false );
  BOOST_TEST( t3.isVector() == true );
}

// Chapter 1 - Tuples
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

// Chapter 1 - Operations
BOOST_AUTO_TEST_CASE( adding_tuples )
{
    Tuple a(3, -2, 5, 1);
    Tuple b(-2, 3, 1, 0);

    Tuple c = a+b;

    Tuple result(1,1,6,1);

    BOOST_TEST(c.isEqual(result));
}

// Chapter 1 - Tuples
BOOST_AUTO_TEST_CASE (subtracting_tuples)
{

    Tuple p1 = point(3,2,1);
    Tuple v1 = vector(3,2,1);
    Tuple p2 = point(5,6,7);
    Tuple v2 = vector(5,6,7);
    Tuple result1 = vector(-2, -4, -6);
    Tuple result2 = point(-2, -4, -6);

    // Subtracting two points

    Tuple t1 = p1 - p2; // the vector pointing from p2 to p1

    BOOST_TEST(t1.isEqual(result1));
    BOOST_TEST(t1.isVector());

    // Subtracting a vector from a point

    Tuple t2 = p1 - v2; // subtract a vector from a point is just moving /backward/ by the given vector

    BOOST_TEST(t2.isEqual(result2));
    BOOST_TEST(t2.isPoint());

    // Subtracting two vectors - returns a vector representing the change in direction between the two

    Tuple t3 = v1 - v2;
    BOOST_TEST(t3.isEqual(result1));
    BOOST_TEST(t3.isVector());

}
