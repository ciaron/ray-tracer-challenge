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

  std::initializer_list<float> vals = { 0  ,  2  ,  3  ,  4,
                                        5.5,  6.5,  7.5,  8.5,
                                        9  , 10  , 11  , 12,
                                       13.5, 14.5, 15.5, 16.5
                       };
  Matrix m( nrows, ncols, vals );

  // Or directly construct Matrix with initializer_list for values
  // Matrix m( nrows, ncols, { 0  ,  2   ,  3   ,  4,
  //                           5.5,  6.5 ,  7.5 ,  8.5,
  //                           9  , 10   , 11   , 12,
  //                          13.5, 14.5 , 15.5 , 16.5
  //                        } );

  m(0,0) = 1.0;

  BOOST_TEST(m(0,0) == 1);
  BOOST_TEST(m(0,3) == 4);
  BOOST_TEST(m(1,0) == 5.5);
  BOOST_TEST(m(1,2) == 7.5);
  BOOST_TEST(m(2,2) == 11);
  BOOST_TEST(m(3,0) == 13.5);
  BOOST_TEST(m(3,2) == 15.5);

  // "old" way of setting values
  float vals2[4] = { -3, 5, 1, -2 };
  Matrix m2{2,2};
  m2.set(vals2);

  BOOST_TEST(m2(0,0) == -3);
  BOOST_TEST(m2(0,1) == 5);
  BOOST_TEST(m2(1,0) == 1);
  BOOST_TEST(m2(1,1) == -2);

  //float vals3[9] = { -3, 5, 0, 1, -2, -7, 0, 1, 1 };
  Matrix m3(3,3,{ -3, 5, 0, 1, -2, -7, 0, 1, 1 });
  //m3.set(vals3);
  BOOST_TEST(m3(0,0) == -3);
  BOOST_TEST(m3(1,1) == -2);
  BOOST_TEST(m3(2,2) == 1);
}

//BOOST_TEST_DONT_PRINT_LOG_VALUE(Matrix)

BOOST_AUTO_TEST_CASE ( matrix_equality ) {

    std::initializer_list<float>  valsA = {
        1,2,3,4,
        5,6,7,8,
        9,8,7,6,
        5,4,3,2
    };

    std::initializer_list<float> valsB = {
        1,2,3,4,
        5,6,7,8,
        9,8,7,6,
        5,4,3,2
    };

    std::initializer_list<float> valsC = {
        2,3,4,5,
        6,7,8,9,
        8,7,6,5,
        4,3,2,1
    };

    Matrix A (4, 4, valsA);
    Matrix B (4, 4, valsB);
    Matrix C (4, 4, valsC);

    //A.set(valsA);
    //B.set(valsB);
    //C.set(valsC);

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

        std::initializer_list<float> valsA = {
            1,2,3,4,
            5,6,7,8,
            9,8,7,6,
            5,4,3,2
        };

        std::initializer_list<float> valsB = {
            -2,1,2,3,
            3,2,1,-1,
            4,3,6,5,
            1,2,7,8
        };

        std::initializer_list<float> valsC = {
            20,22,50,48,
            44,54,114,108,
            40,58,110,102,
            16,26,46,42
        };

        Matrix A(4, 4, valsA);
        Matrix B(4, 4, valsB);
        Matrix C(4, 4, valsC);
        //A.set(valsA); B.set(valsB); C.set(valsC);

        BOOST_TEST((A*B) == C);
}

BOOST_AUTO_TEST_CASE ( matrix_tuple_multiply ) {

        std::initializer_list<float> valsA = {
            1,2,3,4,
            2,4,4,2,
            8,6,4,1,
            0,0,0,1
        };
        std::initializer_list<float> valsB = {
            1,2,3,1
        };
        std::initializer_list<float> valsC = {
            18,24,33,1
        };

        Matrix A(4,4,valsA);
        Matrix B(4,1,valsB);
        Matrix C(4,1,valsC);

        //BOOST_TEST((A*B)==C);

        Tuple b(1,2,3,1);
        Tuple c(18,24,33,1);

        BOOST_TEST((A*b) == c);
}

BOOST_AUTO_TEST_CASE ( identity_matrix ) {
  std::initializer_list<float> valsA = {
    0,1,2,4,
    1,2,4,8,
    2,4,8,16,
    4,8,16,32
  };
  std::initializer_list<float> valsI = {
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    0,0,0,1
  };
  Matrix A(4,4,valsA);
  Matrix I(4,4,valsI);

  BOOST_TEST((A*I) == A);

  Tuple t(1,2,3,4);
  BOOST_TEST((I*t) == t);
  BOOST_TEST((t*I) == t);

}

BOOST_AUTO_TEST_CASE(transpose) {
  std::initializer_list<float> valsT = {
    0,9,1,0,
    9,8,8,0,
    3,0,5,5,
    0,8,3,8
  };
  Matrix Tr{4,4}; Tr.set(valsT);

  std::initializer_list<float> valsA = {
    0,9,3,0,
    9,8,0,8,
    1,8,5,3,
    0,0,5,8
  };
  Matrix A(4,4,valsA);

  Matrix T(4,4);
  T=A.transpose();

  BOOST_TEST(T==Tr);

  // tranpose identity matrix
  std::initializer_list<float> valsI = {
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    0,0,0,1
  };
  Matrix I(4,4,valsI);
  T = I.transpose();
  BOOST_TEST(T==I);
}

BOOST_AUTO_TEST_CASE (matrix_determinant)
{
  // determinant of a 2x2 Matrix
  Matrix A(2, 2, {1,5,-3,2});
  BOOST_TEST(equal(A.determinant(), 17));
}

BOOST_AUTO_TEST_CASE (submatrices)
{

  // submatrix of a 3x3
  Matrix B(3, 3, {1,5,0,-3,2,7,0,6,-3});
  Matrix Sub(2, 2, {-3,2,0,6});

  Matrix C(2,2);
  C = B.submatrix(0,2);

  BOOST_TEST(C==Sub);

  // submatrix of a 4x4
  Matrix D(4,4,{-6,1,1,6,-8,5,8,6,-1,0,8,2,-7,1,-1,1});
  Matrix Dsub(3,3);
  Matrix Sub2(3,3,{-6,1,6,-8,8,6,-7,-1,1});

  Dsub = D.submatrix(2,1);
  BOOST_TEST(Dsub == Sub2);
}

BOOST_AUTO_TEST_CASE (minor)
{
  Matrix A(3,3,{3,5,0,2,-1,-7,6,-1,5});

  float m = A.minor(1,0);
  BOOST_TEST(equal(m, 25));
}

BOOST_AUTO_TEST_CASE (cofactor)
{
  Matrix A(3,3,{3,5,0,2,-1,-7,6,-1,5});

  BOOST_TEST(equal(A.minor(0,0), -12));
  BOOST_TEST(equal(A.cofactor(0,0), -12));
  BOOST_TEST(equal(A.minor(1,0), 25));
  BOOST_TEST(equal(A.cofactor(1,0), -25));
}

BOOST_AUTO_TEST_CASE (determinant_large)
{

  Matrix A(3,3,{1,2,6,-5,8,-4,2,6,4});

  BOOST_TEST(equal(A.cofactor(0,0), 56));
  BOOST_TEST(equal(A.cofactor(0,1), 12));
  BOOST_TEST(equal(A.cofactor(0,2), -46));
  BOOST_TEST(equal(A.determinant(),-196));

  Matrix B(4,4,{-2, -8, 3, 5, -3,1,7,3,1,2,-9,6,-6,7,7,-9});

  BOOST_TEST(equal(B.cofactor(0,0), 690));
  BOOST_TEST(equal(B.cofactor(0,1), 447));
  BOOST_TEST(equal(B.cofactor(0,2), 210));
  BOOST_TEST(equal(B.cofactor(0,3), 51));
  BOOST_TEST(equal(B.determinant(),-4071));

}

BOOST_AUTO_TEST_CASE (invertibility)
{
  Matrix A(4,4,{
      6,4,4,4,
      5,5,7,6,
      4,-9,3,-7,
      9,1,7,-6
  });

  Matrix B(4,4,{
      -4,2,-2,-3,
      9,6,2,6,
      0,-5,1,-5,
      0,0,0,0
  });

  BOOST_TEST(A.isInvertible());
  BOOST_TEST(!B.isInvertible());
}

BOOST_AUTO_TEST_CASE (inversion) {
  Matrix A(4,4,{-5,2,6,-8,1,-5,1,8,7,7,-6,-7,1,-3,7,4});

  Matrix Ainv(4,4,
    {
      0.21805,  0.45113,  0.24060, -0.04511,
     -0.80827, -1.45677, -0.44361,  0.52068,
     -0.07895, -0.22368, -0.05263,  0.19737,
     -0.52256, -0.81391, -0.30075,  0.30639    }
  );

  Matrix B = A.inverse();

  BOOST_TEST(equal(A.determinant(), 532));
  BOOST_TEST(equal(A.cofactor(2,3), -160));
  BOOST_TEST(equal(B(3,2), -160.0/532));
  BOOST_TEST(equal(A.cofactor(3,2), 105));
  BOOST_TEST(equal(B(2,3), 105.0/532));

  BOOST_TEST(B==Ainv);

  A.set({
    8, -5,  9,  2,
    7,  5,  6,  1,
   -6,  0,  9,  6,
   -3,  0, -9, -4
  });

  Ainv.set({
    -0.15385, -0.15385, -0.28205, -0.53846,
    -0.07692,  0.12308,  0.02564,  0.03077,
     0.35897,  0.35897,  0.43590,  0.92308,
    -0.69231, -0.69231, -0.76923, -1.92308
  });

  BOOST_TEST(A.inverse()==Ainv);

  A.set({
    9,  3,  0,  9,
   -5, -2, -6, -3,
   -4,  9,  6,  4,
   -7,  6,  6,  2
  });

  Ainv.set({
    -0.04074, -0.07778,  0.14444, -0.22222,
    -0.07778,  0.03333,  0.36667, -0.33333,
    -0.02901, -0.14630, -0.10926,  0.12963,
     0.17778,  0.06667, -0.26667,  0.33333
  });

  BOOST_TEST(A.inverse()==Ainv);

  A.set({
    3, -9,  7,  3,
    3, -8,  2, -9,
   -4,  4,  4,  1,
   -6,  5, -1,  1
  });

  B.set({
    8,  2, 2, 2,
    3, -1, 7, 0,
    7,  0, 5, 4,
    6, -2, 0, 5
  });

  Matrix C = A*B;
  BOOST_TEST((C*B.inverse()) == A);
}
