#include "Matrix.h"
using namespace std;

// Matrix:: Matrix(int rows, int cols) :ROWS{rows},COLS{cols} {
//   m = new float[ROWS * COLS];
// }
Matrix::Matrix(int rows, int cols) :ROWS{rows},COLS{cols} {
  matrix = new float[ROWS * COLS];

}

int Matrix::rows() const { return ROWS; }
int Matrix::cols() const { return COLS; }

  // inline vector<float>& Matrix::row(int r) const {
  //   return m[COLS*r];
  // }
