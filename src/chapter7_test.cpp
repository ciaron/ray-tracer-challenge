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

BOOST_AUTO_TEST_CASE (inside_outside){
  Ray r(Point(0,0,-5), Vector(0,0,1));
  Sphere shape;
  Intersection i{4.0, shape};
  auto comps = prepare_computations(i, r);
  BOOST_TEST(comps.inside == false);

  r = Ray(Point(0,0,0), Vector(0,0,1));
  i = Intersection(1, shape);
  comps = prepare_computations(i, r);
  BOOST_TEST(comps.point == Point(0,0,1));
  BOOST_TEST(comps.eyev == Vector(0,0,-1));
  BOOST_TEST(comps.normalv == Vector(0,0,-1));
  BOOST_TEST(comps.inside == true);
}

BOOST_AUTO_TEST_CASE (shade_tests) {
  World w;
  Ray r(Point(0,0,-5), Vector(0,0,1));

  Sphere s1 = w.spheres()[0];
  auto i = Intersection(4.0, s1);
  auto comps = prepare_computations(i, r);
  auto c = shade_hit(w, comps);
  BOOST_TEST(Color(0.38066, 0.47583, 0.2855) == c);
}

BOOST_AUTO_TEST_CASE(color_at_tests) {
  World w;
  Ray r(Point(0,0,-5), Vector(0,1,0));

  // The colour when a ray misses
  Color c = color_at(w, r);
  BOOST_TEST(c == Color(0,0,0));

  // the colour when a ray hits
  r = Ray(Point(0,0,-5), Vector(0,0,1));
  c = color_at(w, r);
  BOOST_TEST(c == Color(0.38066, 0.47583, 0.2855));

  // the colour with an intersection behind the ray

  // outer
  auto ps0 = w.getSphere(0);
  //w.spheres()[0].material.setAmbient(1.0);
  ps0->updateMaterial(1.0);

  auto ps1 = w.getSphere(1);

  // inner
  //cout << "TEST AMBIENT BEFORE " << w.spheres()[1].material.getAmbient() << " at " << &w.spheres()[1].material << endl;
  //cout << "TEST AMBIENT BEFORE " << (*ps1).material.getAmbient() << endl;
  //w.spheres()[1].material.setAmbient(1.0);
  //w.spheres()[1].updateMaterial(1.0);
  ps1->updateMaterial(1.0);
  //cout << "TEST AMBIENT  AFTER " << w.spheres()[1].material.getAmbient() << " at " << &w.spheres()[1].material << endl;
  //cout << "TEST AMBIENT  AFTER " << (*ps1).material.getAmbient() << endl;
  //cout << w.spheres()[1].material.ambient << endl;

  r = Ray(Point(0,0,0.75), Vector(0,0,-1));
  c = color_at(w, r);
  //cout << inner.material.color << endl; // 1 1 1
  BOOST_TEST(c == w.spheres()[1].material.color);

}
