#define BOOST_TEST_MODULE Chapter5 Tests
#define BOOST_TEST_DYN_LINK
#define _USE_MATH_DEFINES

#include <boost/test/unit_test.hpp>
#include "Util.h"
#include "Ray.h"
#include "Point.h"
#include "Vector.h"
//#include "Shape.h"
#include "Sphere.h"
#include "Intersection.h"

using namespace std;

int Shape::count=0;

BOOST_AUTO_TEST_CASE( creating_ray )
{
  Point origin(1,2,3);
  Vector direction(4,5,6);
  Ray r(origin, direction);

  BOOST_TEST(r.origin() == origin);
  BOOST_TEST(r.direction() == direction);
}

BOOST_AUTO_TEST_CASE( point_from_distance ) {
  Ray r(Point(2,3,4), Vector(1,0,0));

  BOOST_TEST(r.position(0) == Point(2,3,4));
  BOOST_TEST(r.position(1) == Point(3,3,4));
  BOOST_TEST(r.position(-1) == Point(1,3,4));
  BOOST_TEST(r.position(2.5) == Point(4.5,3,4));
}

BOOST_AUTO_TEST_CASE( sphere_intersection ) {

    Sphere s;
    Ray r1(Point(0,0,-5), Vector(0,0,1));
    Ray r2(Point(0,1,-5), Vector(0,0,1));
    Ray r3(Point(0,2,-5), Vector(0,0,1));

    // ray intersects at two points
    vector<float> xs1 = r1.intersect(s);
    BOOST_TEST(xs1[0]==4.0);
    BOOST_TEST(xs1[1]==6.0);

    // ray intersects at tangent
    vector<float> xs2 = r2.intersect(s);
    BOOST_TEST(xs2[0]==5.0);
    BOOST_TEST(xs2[1]==5.0);

    // ray misses sphere
    vector<float> xs3 = r3.intersect(s);
    BOOST_TEST(xs3.size() == 0);

    Sphere s2;
    cout << s.id() << " " << s2.id() << endl;
}

BOOST_AUTO_TEST_CASE( tracking_intersections ) {

    // An intersection encapsulates t and object
    Sphere s;
    Intersection i(3.5, s);
    BOOST_TEST(i.t() == 3.5 );
    BOOST_TEST(i.object().id() == s.id());
    //BOOST_TEST(i.object() == s); // TODO

    // aggregating intersections using vector<>
    Intersection i1(1,s);
    Intersection i2(2,s);
    vector<Intersection> xs {i1,i2};
    BOOST_TEST(xs.size()==2);
    BOOST_TEST(equal(xs[0].t(), 1));
    BOOST_TEST(equal(xs[1].t(), 2));

    // Intersect sets the object on the intersection


}
