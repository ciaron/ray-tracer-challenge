#define BOOST_TEST_MODULE Chapter7 Tests
#define BOOST_TEST_DYN_LINK
#define _USE_MATH_DEFINES

#include <boost/test/unit_test.hpp>
#include "Util.h"
#include "Color.h"
#include "Ray.h"
#include "Point.h"
#include "Vector.h"
#include "Sphere.h"
#include "Intersection.h"
#include "Light.h"
#include "Material.h"
#include "World.h"

using namespace std;

int Shape::count=0;

BOOST_AUTO_TEST_CASE( world1 ) {
    // ignore first test case in book - we'll just make default worlds

    Pointlight light(Point(-10, 10, -10), Color(1,1,1));
    Material m1;
    m1.color = Color(0.8, 1.0, 0.6);
    m1.diffuse = 0.7;
    m1.specular = 0.2;

    Sphere s1;
    s1.material = m1;

    Sphere s2;
    s2.set_transform(identity().scaling(0.5, 0.5, 0.5));

    World w;

    BOOST_TEST(w.light() == light);
    //BOOST_TEST(w.find(s1));
    //BOOST_TEST(w.find(s2));
}
