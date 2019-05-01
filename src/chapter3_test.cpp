#define BOOST_TEST_MODULE Chapter3 Tests
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <vector>

#include "Tuple.h"
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

  Matrix m{ nrows, ncols }; // create a new 2x2 matrix
  m.set(vals);

  m(0,0) = 1.0;

  BOOST_TEST(m(0,0) == 1);
  BOOST_TEST(m(0,3) == 4);
  BOOST_TEST(m(1,0) == 5.5);
  BOOST_TEST(m(1,2) == 7.5);
  BOOST_TEST(m(2,2) == 11);
  BOOST_TEST(m(3,0) == 13.5);
  BOOST_TEST(m(3,2) == 15.5);

  float vals2[4] = { -3, 5, 1, -2 };
  Matrix m2{2,2};
  m2.set(vals2);

  BOOST_TEST(m2(0,0) == -3);
  BOOST_TEST(m2(0,1) == 5);
  BOOST_TEST(m2(1,0) == 1);
  BOOST_TEST(m2(1,1) == -2);

  float vals3[9] = { -3, 5, 0, 1, -2, -7, 0, 1, 1 };
  Matrix m3{3,3};
  m3.set(vals3);
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
        1,2,3,4,
        5,6,7,8,
        9,8,7,6,
        5,4,3,2
    };

    float valsC [16] = {
        2,3,4,5,
        6,7,8,9,
        8,7,6,5,
        4,3,2,1
    };

    Matrix A {4, 4};
    Matrix B {4, 4};
    Matrix C {4, 4};

    A.set(valsA);
    B.set(valsB);
    C.set(valsC);

    // BOOST_TEST requires that the data type implement the << operator.
    // So we either need to do that, or disable logging:
    // BOOST_TEST_DONT_PRINT_LOG_VALUE(Matrix) (at the file level)
    //cout << A(0,0) << " " << B(0,0) << endl;
    BOOST_TEST(A==B);
    BOOST_TEST(A!=C);

    // or do BOOST_CHECK instead:
    //BOOST_CHECK(A==B);
}
BOOST_AUTO_TEST_CASE ( matrix_multiply ) {

        float valsA [16] = {
            1,2,3,4,
            5,6,7,8,
            9,8,7,6,
            5,4,3,2
        };

        float valsB [16] = {
            -2,1,2,3,
            3,2,1,-1,
            4,3,6,5,
            1,2,7,8
        };

        float valsC [16] = {
            20,22,50,48,
            44,54,114,108,
            40,58,110,102,
            16,26,46,42
        };

        Matrix A {4,4}; Matrix B {4,4}; Matrix C {4,4};
        A.set(valsA); B.set(valsB); C.set(valsC);

        BOOST_TEST((A*B) == C);

}

BOOST_AUTO_TEST_CASE ( matrix_tuple_multiply ) {

        float valsA [16] = {
            1,2,3,4,
            2,4,4,2,
            8,6,4,1,
            0,0,0,1
        };
        float valsB [4] = {
            1,2,3,1
        };
        float valsC [4] = {
            18,24,33,1
        };

        Matrix A {4,4}; A.set(valsA);
        Matrix B {4,1}; B.set(valsB);
        Matrix C {4,1}; C.set(valsC);

        //BOOST_TEST((A*B)==C);

        Tuple b(1,2,3,1);
        Tuple c(18,24,33,1);

        BOOST_TEST((A*b) == c);
}

BOOST_AUTO_TEST_CASE ( identity_matrix ) {
  float valsA[16] = {
    0,1,2,4,
    1,2,4,8,
    2,4,8,16,
    4,8,16,32
  };
  float valsI[16] = {
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    0,0,0,1
  };
  Matrix A{4,4}; A.set(valsA);
  Matrix I{4,4}; I.set(valsI);

  BOOST_TEST((A*I) == A);

  Tuple t(1,2,3,4);
  BOOST_TEST((I*t) == t);
  BOOST_TEST((t*I) == t);

}

BOOST_AUTO_TEST_CASE(transpose) {
  float valsT[16] = {
    0,9,1,0,
    9,8,8,0,
    3,0,5,5,
    0,8,3,8
  };
  Matrix Tr{4,4}; Tr.set(valsT);

  float valsA[16] = {
    0,9,3,0,
    9,8,0,8,
    1,8,5,3,
    0,0,5,8
  };
  Matrix A{4,4}; A.set(valsA);

  Matrix T{4,4};
  T=A.transpose();

  BOOST_TEST(T==Tr);

  // tranpose identity matrix
  float valsI[16] = {
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    0,0,0,1
  };
  Matrix I{4,4}; I.set(valsI);
  T = I.transpose();
  BOOST_TEST(T==I);

}
