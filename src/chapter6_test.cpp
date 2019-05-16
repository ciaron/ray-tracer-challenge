#define BOOST_TEST_MODULE Chapter6 Tests
#define BOOST_TEST_DYN_LINK
#define _USE_MATH_DEFINES

#include <boost/test/unit_test.hpp>
#include "Util.h"
#include "Color.h"
#include "Matrix.h"
#include "Ray.h"
#include "Point.h"
#include "Vector.h"
#include "Sphere.h"
#include "Intersection.h"
#include "Light.h"
#include "Material.h"

using namespace std;

int Shape::count=0;

BOOST_AUTO_TEST_CASE( normal_at )
{
  Sphere s;
  auto n1 = s.normal_at(Point(1,0,0));
  BOOST_TEST(n1==Vector(1,0,0));

  auto n2 = s.normal_at(Point(0,1,0));
  BOOST_TEST(n2==Vector(0,1,0));

  auto n3 = s.normal_at(Point(0,0,1));
  BOOST_TEST(n3==Vector(0,0,1));

  float p = sqrt(3.0)/3.0;
  auto n4 = s.normal_at(Point(p,p,p));
  BOOST_TEST(n4==Vector(p,p,p));

  Vector v = n4;
  v.normalize();
  BOOST_TEST(n4 == v);
  BOOST_TEST(n4 == normalize(n4)); // alternate version in Util.h
}

BOOST_AUTO_TEST_CASE (transforming_normals) {
  Sphere s;
  s.set_transform(identity().translation(0,1,0));
  //s.set_transform(translation(0,1,0));

  Vector n = s.normal_at(Point(0, 1.70711, -0.70711));
  BOOST_TEST(n==Vector(0, 0.70711, -0.70711));

  s.set_transform(identity().scaling(1, 0.5, 1).rotation_z(M_PI/5.0));
  Vector n2 = s.normal_at(Point(0, sqrt(2)/2, -sqrt(2)/2));
  BOOST_TEST(n2==Vector(0, 0.97014, -0.24254));
}

BOOST_AUTO_TEST_CASE(reflecting_vectors) {
  Vector v(1,-1,0);
  Vector n(0,1,0);

  Vector r = v.reflect(n);
  BOOST_TEST(r == Vector(1,1,0));
}

BOOST_AUTO_TEST_CASE ( light_setup ) {
    Color intensity(1,1,1);
    Point position(0,0,0);

    Pointlight light(position, intensity);

    BOOST_TEST(light.position == position);
    BOOST_TEST(light.intensity == intensity);

    Material m1;
    BOOST_TEST(m1.color == Color(1,1,1));
    BOOST_TEST(equal(m1.ambient  , 0.1));
    BOOST_TEST(equal(m1.diffuse  , 0.9));
    BOOST_TEST(equal(m1.specular , 0.9));
    BOOST_TEST(equal(m1.shininess, 200.0));

    // a sphere has a default Material
    Sphere sd;
    Material md;
    BOOST_TEST(sd.material == md);

    // a sphere may be assiged a material
    Sphere s;
    Material m2;
    m2.ambient = 1.0;
    s.material = m2;
    BOOST_TEST(s.material == m2);
}

BOOST_AUTO_TEST_CASE(lighting_test) {

    Material m;
    Point position(0,0,0);

    //lighting with the eye between the light and the surface
    Vector eyev(0,0,-1);
    Vector normalv(0,0,-1);
    Pointlight light(Point(0,0,-10), Color(1,1,1));
    Color result = lighting(m, light, position, eyev, normalv);
    BOOST_TEST(result == Color(1.9, 1.9, 1.9));

    // lighting with the eye between the light and surface, eye offset 45'
    eyev = Vector(0, sqrt(2)/2, sqrt(2)/2);
    normalv = Vector(0,0,-1);
    light = Pointlight(Point(0,0,-10), Color(1,1,1));
    result = lighting(m, light, position, eyev, normalv);
    BOOST_TEST(result == Color(1.0, 1.0, 1.0));

    // lighting with eye opposite surface, light offset 45'
    eyev = Vector(0,0,-1);
    normalv = Vector(0,0,-1);
    light = Pointlight(Point(0,10,-10), Color(1,1,1));
    result = lighting(m, light, position, eyev, normalv);
    BOOST_TEST(result == Color(0.7364,0.7364,0.7364));

    // lighting with the eye in the path of the reflection vector
    eyev = Vector(0,-sqrt(2)/2,-sqrt(2)/2);
    normalv = Vector(0,0,-1);
    light = Pointlight(Point(0,10,-10), Color(1,1,1));
    result = lighting(m, light, position, eyev, normalv);
    BOOST_TEST(result == Color(1.6364, 1.6364, 1.6364));

    // lighting with the light behind the surface
    eyev = Vector(0,0,-1);
    normalv = Vector(0,0,-1);
    light = Pointlight(Point(0,0,10), Color(1,1,1));
    result = lighting(m, light, position, eyev, normalv);
    BOOST_TEST(result == Color(0.1,0.1,0.1));
}
