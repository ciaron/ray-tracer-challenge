#define BOOST_TEST_MODULE Chapter2 Tests
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <vector>
#include <string>

#include "Util.h"
#include "Color.h"
#include "Canvas.h"

using namespace std;

BOOST_AUTO_TEST_CASE( color_component_test )
{
  Color c(-0.5, 0.4, 1.7);
  BOOST_TEST( equal(c.red(), -0.5));
  BOOST_TEST( equal(c.green(), 0.4));
  BOOST_TEST( equal(c.blue(), 1.7));
}

BOOST_AUTO_TEST_CASE( color_operators )
{
    // addition
    Color c1(0.9, 0.6, 0.75);
    Color c2(0.7, 0.1, 0.25);
    Color cr1 = c1 + c2;

    // subtraction
    Color cr2 = c1 - c2;

    // multiplication by a scalar
    Color c3(0.2, 0.3, 0.4);
    Color cr3 = c3 * 2;

    // multiple two colors
    Color c4(1, 0.2, 0.4);
    Color c5(0.9, 1, 0.1);
    Color cr4 = c4 * c5;

    BOOST_TEST( cr1.isEqual(Color(1.6, 0.7, 1.0)));
    BOOST_TEST( cr2.isEqual(Color(0.2, 0.5, 0.5)));
    BOOST_TEST( cr3.isEqual(Color(0.4, 0.6, 0.8)));
    BOOST_TEST( cr4.isEqual(Color(0.9, 0.2, 0.04)));
}

BOOST_AUTO_TEST_CASE( canvas_creation )
{
    // check that a new canvas has the correct dimensions
    int w{10}, h{20};
    Canvas c(w, h);
    BOOST_TEST(c.width() == w);
    BOOST_TEST(c.height() == h);

    // check that all pixels are black
    std::vector<Color> black(w*h, Color(0.0,0.0,0.0));
    BOOST_TEST(c.pixels == black);

    // check that pixel at [2,3] is red
    Color red(1.0,0.0,0.0);
    c.setPixel(2, 3, red);
    BOOST_TEST(c.pixelAt(2,3).isEqual(red) );

}

BOOST_AUTO_TEST_CASE( ppm_creation ) {
    int w{5}, h{3};
    Canvas c(w, h);
    string header = R"(P3)" "\n"
                    R"(5 3)" "\n"
                    R"(255)" "\n";

    BOOST_TEST(canvas_to_ppm(c).rfind(header, 0) != -1); // canvas_to_ppm starts with header

    Color c1(1.5,0,0);
    Color c2(0,0.5,0);
    Color c3(-0.5,0,1);
    c.setPixel(0,0,c1);
    c.setPixel(2,1,c2);
    c.setPixel(4,2,c3);

    string pixeldata = R"(255 0 0 0 0 0 0 0 0 0 0 0 0 0 0 )" "\n"
    R"(0 0 0 0 0 0 0 128 0 0 0 0 0 0 0 )" "\n"
    R"(0 0 0 0 0 0 0 0 0 0 0 0 0 0 255 )" "\n";

    //string pixeldata = ("255 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n0 0 0 0 0 0 0 128 0 0 0 0 0 0 0 \n0 0 0 0 0 0 0 0 0 0 0 0 0 0 255 \n");

    BOOST_TEST(canvas_to_ppm(c).rfind(pixeldata, header.length()) != -1); // after the header we find pixel data
}
