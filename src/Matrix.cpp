#include "Tuple.h"
#include "Matrix.h"
#include "Util.h"

using namespace std;

Matrix::Matrix(unsigned rows, unsigned cols) : ROWS{rows}, COLS{cols} {
    matrix = new float[rows * cols];
}

Matrix::Matrix(unsigned rows, unsigned cols, std::initializer_list<float> data)
 : ROWS{rows}, COLS{cols}, matrix{new float[rows*cols]}
{
    copy(data.begin(), data.end(), matrix);
}

// default constructor
Matrix::Matrix()
{ }

void Matrix::set(float *vals) {
    matrix = vals;
}

void Matrix::set(std::initializer_list<float> vals){
  std::copy(vals.begin(), vals.end(), matrix);
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

Matrix Matrix::operator*(const Matrix& rhs) const {

    // (n,m) x (m,p) = (n,p);
    Matrix result = Matrix{this->ROWS, rhs.COLS}; // initialise result matrix

    for (unsigned row=0; row<this->ROWS; ++row) {
        for (unsigned col=0; col<rhs.COLS; ++col) {
            result(row, col) = matrix[row*COLS+0] * rhs(0,col) +
                               matrix[row*COLS+1] * rhs(1,col) +
                               matrix[row*COLS+2] * rhs(2,col) +
                               matrix[row*COLS+3] * rhs(3,col);
        }
    }
    return result;
}

Tuple Matrix::operator*(const Tuple& b) const {
  Tuple result(0,0,0,0);

  for (unsigned row=0; row<this->ROWS; ++row) {
    result(row) = matrix[row*COLS+0] * b.x() +
                  matrix[row*COLS+1] * b.y() +
                  matrix[row*COLS+2] * b.z() +
                  matrix[row*COLS+3] * b.w();
  }
  return result;
}

// TODO: duplicated the Matrix*Tuple code here...
Point Matrix::operator*(const Point& b) const {
  Point result(0,0,0);

  for (unsigned row=0; row<this->ROWS; ++row) {
    result(row) = matrix[row*COLS+0] * b.x() +
                  matrix[row*COLS+1] * b.y() +
                  matrix[row*COLS+2] * b.z() +
                  matrix[row*COLS+3] * b.w();
  }
  return result;
}
// TODO: duplicated the Matrix*Tuple code here...
Vector Matrix::operator*(const Vector& v) const {
  Vector result(0,0,0);

  for (unsigned row=0; row<this->ROWS; ++row) {
    result(row) = matrix[row*COLS+0] * v.x() +
                  matrix[row*COLS+1] * v.y() +
                  matrix[row*COLS+2] * v.z() +
                  matrix[row*COLS+3] * v.w();
  }
  return result;
}

Matrix Matrix::transpose() const {
  Matrix T{this->rows(), this->cols()};

  for (unsigned row=0; row<this->rows(); ++row) {
    for (unsigned col=0; col<this->cols(); ++col) {
      float v = matrix[row*COLS + col];
      T(col, row) = v;
    }
  }
  return T;
}

float Matrix::determinant() const {
  float det=0.0;

  // 2x2 only (ad-bc)
  if (this->ROWS==2 && this->COLS==2) {
    det = matrix[0]*matrix[3] - matrix[1]*matrix[2];
  } else {
    for (unsigned col=0; col<this->COLS; ++col) {
      det += matrix[col] * this->cofactor(0,col);
    }
  }
  return det;
}

// return a matrix with given row and column removed
Matrix Matrix::submatrix(unsigned delrow, unsigned delcol) const{
  Matrix S{this->rows()-1, this->cols()-1}; // size is one less than original
  unsigned target_idx=0;

  for (unsigned row=0; row<this->ROWS; ++row) {
      for (unsigned col=0; col<this->COLS; ++col) {
        if (col != delcol && row != delrow) {
          S.matrix[target_idx++] = matrix[row*COLS+col];
        }
      }
    }
  return S;
}

float Matrix::minor(unsigned row, unsigned col) const {
  Matrix m = this->submatrix(row, col);
  return m.determinant();
}

float Matrix::cofactor(unsigned row, unsigned col) const {
  float m=minor(row, col);
  if ((row+col) % 2 == 0) {
    return m;
  } else {
    return -m;
  }
}

bool Matrix::isInvertible() const {
  return this->determinant() == 0 ? false : true;
}

Matrix Matrix::inverse() const {
  Matrix M2{this->ROWS, this->COLS};
  float dm = this->determinant();

  if (!this->isInvertible()) {
    return Matrix{0,0};
  } else {
    for (unsigned row=0; row<this->ROWS; ++row) {
      for (unsigned col=0; col<this->COLS; ++col) {
        float c = this->cofactor(row, col);
        M2(col,row) = c/dm;
      }
    }
  }
  return M2;
}

// non-member
Matrix identity() {
  return Matrix(4,4,{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1});
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
   return (A*t);
}
