#define BOOST_TEST_MODULE Chapter3 Tests
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <vector>

#include "Matrix.h"
#include "Util.h"

using namespace std;

BOOST_AUTO_TEST_CASE( matrix_create )
{
  Matrix m{ 4,4 }; // create a new 2x2 matrix

  for (auto c=0; c<=3; ++c) {
    m.at(0,c) = c+1;
  }
  for (auto c=0; c<=3; ++c) {
    m.at(1,c) = c+5.5;
  }
  for (auto c=0; c<=3; ++c) {
    m.at(2,c) = c+9;
  }
  for (auto c=0; c<=3; ++c) {
    m.at(3,c) = c+13.5;
  }

  BOOST_TEST(m.at(0,0) == 1);
  BOOST_TEST(m.at(0,3) == 4);
  BOOST_TEST(m.at(1,0) == 5.5);
  BOOST_TEST(m.at(1,2) == 7.5);
  BOOST_TEST(m.at(2,2) == 11);
  BOOST_TEST(m.at(3,0) == 13.5);
  BOOST_TEST(m.at(3,2) == 15.5);

}
