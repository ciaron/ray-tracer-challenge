#define BOOST_TEST_MODULE Chapter4 Tests
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
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
