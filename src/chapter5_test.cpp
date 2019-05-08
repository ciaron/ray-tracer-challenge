#define BOOST_TEST_MODULE Chapter5 Tests
#define BOOST_TEST_DYN_LINK
#define _USE_MATH_DEFINES

#include <boost/test/unit_test.hpp>
#include "Util.h"
#include "Matrix.h"
#include "Ray.h"
#include "Point.h"
#include "Vector.h"
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
    vector<Intersection> xs1 = r1.intersect(s);
    BOOST_TEST(xs1[0].t()==4.0);
    BOOST_TEST(xs1[1].t()==6.0);

    // ray intersects at tangent
    vector<Intersection> xs2 = r2.intersect(s);
    BOOST_TEST(xs2[0].t()==5.0);
    BOOST_TEST(xs2[1].t()==5.0);

    // ray misses sphere
    vector<Intersection> xs3 = r3.intersect(s);
    BOOST_TEST(xs3.size() == 0);

    // Sphere s2;
    // cout << s.id() << " " << s2.id() << endl;

    // Extra test: equality of intersections
    Intersection i1(1,s);
    Intersection i2(1,s);
    BOOST_TEST(i1==i2);

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
    Ray r(Point(0,0,-0.5), Vector(0,0,1));
    Sphere s2;
    vector<Intersection> xs2 = r.intersect(s2);
    if (xs2.size()!=0) {
        BOOST_TEST(xs2.size() == 2);
        BOOST_TEST(xs2[0].object().id() == s2.id());
        BOOST_TEST(xs2[1].object().id() == s2.id());

    }
}

BOOST_AUTO_TEST_CASE ( identifying_hits_1 ) {
    Sphere s;
    Intersection i1(1, s);
    Intersection i2(2, s);
    vector<Intersection> xs {i2, i1};

    auto i = hit(xs);
    BOOST_TEST(*i==i1);
}
BOOST_AUTO_TEST_CASE ( identifying_hits_2 ) {
    Sphere s;
    Intersection i1(-1, s);
    Intersection i2(1, s);
    vector<Intersection> xs {i2, i1};

    auto i = hit(xs);
    BOOST_TEST(*i==i2);
}
BOOST_AUTO_TEST_CASE ( identifying_hits_3 ) {
    Sphere s;
    Intersection i1(-2, s);
    Intersection i2(-1, s);
    vector<Intersection> xs {i2, i1};

    auto i = hit(xs);
    BOOST_TEST(*i==*i);
}
BOOST_AUTO_TEST_CASE ( identifying_hits_4 ) {
    Sphere s;
    Intersection i1(5, s);
    Intersection i2(7, s);
    Intersection i3(-3, s);
    Intersection i4(2, s);
    vector<Intersection> xs {i1, i2, i3, i4};

    auto i = hit(xs);
    BOOST_TEST(*i==i4);
}

BOOST_AUTO_TEST_CASE (translate_ray) {
    Ray r(Point(1,2,3),Vector(0,1,0));
    Matrix m = identity().translation(3,4,5);

    // Ray::transform returns a shared_ptr to a new Ray
    std::shared_ptr<Ray> r2 = r.transform(m);

    // use ->origin() since r2 is a pointer
    BOOST_TEST(r2->origin() == Point(4,6,8));
    BOOST_TEST(r2->direction() == Vector(0,1,0));
}

BOOST_AUTO_TEST_CASE (scale_ray) {
    Ray r(Point(1,2,3),Vector(0,1,0));
    Matrix m = identity().scaling(2,3,4);

    // Ray::transform returns a shared_ptr to a new Ray
    //std::shared_ptr<Ray> r2 = r.transform(m);
    // or, more simply:
    auto r2 = r.transform(m);

    // use ->origin() since r2 is a pointer
    BOOST_TEST(r2->origin() == Point(2,6,12));
    BOOST_TEST(r2->direction() == Vector(0,3,0));
}

BOOST_AUTO_TEST_CASE(sphere_transforms) {
    Sphere s;
    BOOST_TEST(s.get_transform() == identity());

    Matrix t = identity().translation(2,3,4);
    s.set_transform(t);
    BOOST_TEST(s.get_transform() == t);
}

BOOST_AUTO_TEST_CASE (intersect_scaled_sphere_with_ray) {
    Ray r(Point(0,0,-5), Vector(0,0,1));
    Sphere s;

    s.set_transform(identity().scaling(2,2,2));
    vector<Intersection> xs = r.intersect(s);

    BOOST_TEST(xs.size() == 2);
    BOOST_TEST(equal(xs[0].t(), 3));
    BOOST_TEST(equal(xs[1].t(), 7));
}

BOOST_AUTO_TEST_CASE (intersect_translated_sphere_with_ray) {
    Ray r(Point(0,0,-5), Vector(0,0,1));
    Sphere s;
    s.set_transform(identity().translation(5,0,0));
    auto xs = r.intersect(s);
    BOOST_TEST(xs.size()==0);
}
