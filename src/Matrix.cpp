#include "Matrix.h"
using namespace std;

Matrix::Matrix(unsigned rows, unsigned cols, float m[]) : ROWS{rows}, COLS{cols}, matrix{*m} { }

unsigned Matrix::rows() const { return ROWS; }
unsigned Matrix::cols() const { return COLS; }

// below: body of inline functions needs to be in the header
// so we make these non-inline here.
//inline
float& Matrix::operator() (unsigned row, unsigned col)
{
    return matrix[COLS*row + col];
}

//inline
float Matrix::operator() (unsigned row, unsigned col) const
{
  return matrix[COLS*row + col];
}
