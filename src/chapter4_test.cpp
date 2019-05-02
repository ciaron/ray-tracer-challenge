#define BOOST_TEST_MODULE Chapter4 Tests
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "Point.h"
#include "Transform.h"

using namespace std;

BOOST_AUTO_TEST_CASE( point_translation )
{
    Point p(-3,4,5);
    Transform t;
    t.translation(5, -3, 2);
    BOOST_TEST((t*p) == Point(2,1,7));
}
