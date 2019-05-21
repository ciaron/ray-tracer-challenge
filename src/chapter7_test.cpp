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
#include "Computations.h"

using namespace std;

int Shape::count=0;

BOOST_AUTO_TEST_CASE( world ) {
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
    BOOST_TEST(w.contains(s1));
    BOOST_TEST(w.contains(s2));
}

BOOST_AUTO_TEST_CASE(intersect_world) {
  World w;
  Ray r(Point(0,0,-5), Vector(0,0,1));

  // find all the intersection in our world with a given ray.
  vector <Intersection> xs = w.intersect(r); // returns sorted

  BOOST_TEST(xs.size() == 4);
  BOOST_TEST(xs[0].t() == 4);
  BOOST_TEST(xs[1].t() == 4.5);
  BOOST_TEST(xs[2].t() == 5.5);
  BOOST_TEST(xs[3].t() == 6);

}

BOOST_AUTO_TEST_CASE (_prepare_computations) {
  Ray r(Point(0,0,-5), Vector(0,0,1));
  Sphere shape;
  Intersection i{4.0, shape};
  Computations comps = prepare_computations(i, r);

  BOOST_TEST(comps.t == i.t());
  BOOST_TEST(comps.object == i.object());
  BOOST_TEST(comps.point == Point(0,0,-1));
  BOOST_TEST(comps.eyev == Vector(0,0,-1));
  BOOST_TEST(comps.normalv == Vector(0,0,-1));
}
