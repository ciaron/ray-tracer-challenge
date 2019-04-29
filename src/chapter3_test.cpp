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
  // without constexpr, vals fails to initialize using nrows*ncols
  constexpr unsigned nrows = 4;
  constexpr unsigned ncols = 4;
  float vals[nrows * ncols] = {0, 2, 3, 4,
                               5.5, 6.5, 7.5, 8.5,
                               9, 10, 11, 12,
                               13.5, 14.5, 15.5, 16.5
                         };

  Matrix m{ nrows, ncols, vals }; // create a new 2x2 matrix
  m(0,0) = 1.0;

  BOOST_TEST(m(0,0) == 1);
  BOOST_TEST(m(0,3) == 4);
  BOOST_TEST(m(1,0) == 5.5);
  BOOST_TEST(m(1,2) == 7.5);
  BOOST_TEST(m(2,2) == 11);
  BOOST_TEST(m(3,0) == 13.5);
  BOOST_TEST(m(3,2) == 15.5);

  float vals2[4] = { -3, 5, 1, -2 };
  Matrix m2{2,2,vals2};
  BOOST_TEST(m2(0,0) == -3);
  BOOST_TEST(m2(0,1) == 5);
  BOOST_TEST(m2(1,0) == 1);
  BOOST_TEST(m2(1,1) == -2);

  float vals3[9] = { -3, 5, 0, 1, -2, -7, 0, 1, 1 };
  Matrix m3{3,3,vals3};
  BOOST_TEST(m3(0,0) == -3);
  BOOST_TEST(m3(1,1) == -2);
  BOOST_TEST(m3(2,2) == 1);

}

//BOOST_TEST_DONT_PRINT_LOG_VALUE(Matrix)

BOOST_AUTO_TEST_CASE ( matrix_equality ) {

    float valsA [16] = {
        1,2,3,4,
        5,6,7,8,
        9,8,7,6,
        5,4,3,2
    };

    float valsB [16] = {
        2,2,3,4,
        5,6,7,8,
        9,8,7,6,
        5,4,3,2
    };


    Matrix A {4, 4, valsA};
    Matrix B {4, 4, valsB};

    // BOOST_TEST requires that the data type implement the << operator.
    // So we either need to do that, or disable logging:
    // BOOST_TEST_DONT_PRINT_LOG_VALUE(Matrix) (at the file level)
    cout << A(0,0) << " " << B(0,0) << endl;
    BOOST_TEST(A==B);

    // or do BOOST_CHECK instead:
    //BOOST_CHECK(A==B);

}
