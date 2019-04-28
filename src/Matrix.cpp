#include "Matrix.h"
using namespace std;

Matrix:: Matrix(int rows, int cols) :ROWS{rows},COLS{cols} {
  m = new float[ROWS * COLS];
}

int Matrix::rows() const { return ROWS; }
int Matrix::cols() const { return COLS; }
