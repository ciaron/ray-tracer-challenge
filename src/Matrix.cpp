#include "Tuple.h"
#include "Matrix.h"
#include "Util.h"

using namespace std;

Matrix::Matrix(unsigned rows, unsigned cols) : ROWS{rows}, COLS{cols} {
    matrix = new float[rows * cols];
}

void Matrix::set(float *vals) {
    matrix = vals;
}

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

bool Matrix::operator== (const Matrix& rhs) const
{
    return (equal(this->matrix[0], rhs(0,0)));
}

bool Matrix::operator!= (const Matrix& rhs) const
{
    return !(*this==rhs);
}

Matrix Matrix::operator*(const Matrix& B) {

    // (n,m) x (m,p) = (n,p);
    Matrix result = Matrix{this->ROWS, B.COLS};

    //Matrix A=this;
    for (unsigned row=0; row<this->ROWS; ++row) {
        for (unsigned col=0; col<B.COLS; ++col) {
            result(row, col) = matrix[row*COLS+0] * B(0,col) +
                               matrix[row*COLS+1] * B(1,col) +
                               matrix[row*COLS+2] * B(2,col) +
                               matrix[row*COLS+3] * B(3,col);
        }
    }
    return result;
}

Tuple Matrix::operator*(const Tuple& b) {
  Tuple result(0,0,0,0);

  for (unsigned row=0; row<this->ROWS; ++row) {
    result(row) = matrix[row*COLS+0] * b.x() +
                  matrix[row*COLS+1] * b.y() +
                  matrix[row*COLS+2] * b.z() +
                  matrix[row*COLS+3] * b.w();
  }
  cout << result << " " << b << endl;
  return result;
}

Matrix Matrix::transpose() {
  Matrix T{this->rows(), this->cols()};

  for (unsigned row=0; row<this->rows(); ++row) {
    for (unsigned col=0; col<this->cols(); ++col) {
      float v = matrix[row*COLS + col];
      T(col, row) = v;
    }
  }
  return T;
}

// this must be declared outside the class. See
// https://stackoverflow.com/questions/10744787/operator-must-take-exactly-one-argument
// https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=vs-2019
ostream& operator<<(ostream& os, const Matrix& rhs)
{
    // simply print the matrix dimensions for now. TODO
    //os << rhs.ROWS << "x" << rhs.COLS;
    os << endl;
    for (unsigned row=0; row<rhs.ROWS; ++row) {
      for (unsigned col=0; col<rhs.COLS; ++col) {
        os << rhs(row,col) << " ";
      }
      os << endl;
    }
    os << endl;
    return os;
}

Tuple operator*(const Tuple& t, const Matrix& A) {
   //return A*t;
   return t;
}
