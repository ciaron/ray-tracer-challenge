#define BOOST_TEST_MODULE Tuple Test
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "Tuple.h"
#include "Util.h"
#include "Point.h"
#include "Vector.h"
#include <cmath>
#include <cstdlib>

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
    //Tuple p = point(4, -4, 3);
    Point p {4, -4, 3};
    Tuple t4(4, -4, 3, 1.0);       // w=1.0, a point

    //Tuple v = vector(4, -4, 3);
    Vector v {4, -4, 3};
    Tuple t5(4.3, -4.2, 3.1, 0.0); // w=0.0, a vector

    BOOST_TEST(p.isPoint() == true);
    BOOST_TEST(p.isEqual(t4));

    BOOST_TEST(v.isVector() == true);
    BOOST_TEST(v.isEqual(t5));
}

// Chapter 1 - Tuples
BOOST_AUTO_TEST_CASE( point_derived_class )
{
    Point p {4, -4, 3};
    Tuple t(4, -4, 3, 1.0);       // w=1.0, a point

    BOOST_TEST(p.isPoint() == true);
    BOOST_TEST(p.isEqual(t));

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

    Point p1 = Point(3,2,1);
    Vector v1 = Vector(3,2,1);
    Point p2 = Point(5,6,7);
    Vector v2 = Vector(5,6,7);
    Vector result1 = Vector(-2, -4, -6);
    Point result2 = Point(-2, -4, -6);

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

// Chapter 1 - Tuples
BOOST_AUTO_TEST_CASE (negating_tuples)
{
    // Subtracting a vector from the zero vector
    Vector zero = Vector(0,0,0);
    Vector v = Vector(1, -2, 3);
    BOOST_TEST((zero-v).isEqual(Vector(-1, 2, -3)));

    // negate operator
    Tuple a(1, -2, 3, -4);
    BOOST_TEST((-a).isEqual(Tuple(-1, 2, -3, 4)));
}

// Chapter 1 - Tuples
BOOST_AUTO_TEST_CASE (scaling_tuples)
{
    Tuple a(1, -2, 3, -4);
    BOOST_TEST((a*3.5).isEqual(Tuple(3.5, -7, 10.5, -14)));
    BOOST_TEST((a*0.5).isEqual(Tuple(0.5, -1, 1.5, -2)));
    BOOST_TEST((a/2).isEqual(Tuple(0.5, -1, 1.5, -2)));

}

// Chapter 1 - Tuples
BOOST_AUTO_TEST_CASE (tuple_magnitude)
{
    Vector v1 = Vector(1, 0, 0);
    Vector v2 = Vector(0, 1, 0);
    Vector v3 = Vector(0, 0, 1);
    Vector v4 = Vector(1, 2, 3);
    Vector v5 = Vector(-1, -2, -3);
    BOOST_TEST(equal(v1.magnitude(), 1));
    BOOST_TEST(equal(v2.magnitude(), 1));
    BOOST_TEST(equal(v3.magnitude(), 1));
    BOOST_TEST(equal(v4.magnitude(), sqrt(14)));
    BOOST_TEST(equal(v5.magnitude(), sqrt(14)));
}

// Chapter 1 - Tuples
BOOST_AUTO_TEST_CASE (tuple_normalize)
{
    Vector v1 = Vector(4, 0, 0);
    Vector v2 = Vector(1, 2, 3);

    BOOST_TEST(v1.normalize().isEqual(Vector(1,0,0)));
    BOOST_TEST(v2.normalize().isEqual(Vector(0.26726, 0.53452, 0.80178)));

    BOOST_TEST(equal(v2.normalize().magnitude(), 1));

}

// Chapter 1 - Tuples
BOOST_AUTO_TEST_CASE (dot_product) // 1 means identical vectors, -1 pointing in opposite directions
                                   // cosine of angle between unit vectors
{
    Vector v1 = Vector(1,2,3);
    Vector v2 = Vector(2,3,4);

    BOOST_TEST(equal(v1.dot(v2), 20));
}

// Chapter 1 - Tuples
BOOST_AUTO_TEST_CASE (cross_product) // a new vector perpendicular to the originals. Order matters!
{
    Vector v1 = Vector(1,2,3);
    Vector v2 = Vector(2,3,4);

    BOOST_TEST(v1.cross(v2).isEqual(Vector(-1, 2, -1)));
    BOOST_TEST(v2.cross(v1).isEqual(Vector(1, -2, 1)));
}
