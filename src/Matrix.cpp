#include "Tuple.h"
#include "Matrix.h"
#include "Util.h"
#include <cmath>

using namespace std;

Matrix::Matrix(unsigned rows, unsigned cols) : ROWS{rows}, COLS{cols} {
    matrix = new double[rows * cols];
}

Matrix::Matrix(unsigned rows, unsigned cols, std::initializer_list<double> data)
 : ROWS{rows}, COLS{cols}, matrix{new double[rows*cols]}
{
    copy(data.begin(), data.end(), matrix);
}

// default constructor
Matrix::Matrix()
{ }

void Matrix::set(double *vals) {
    matrix = vals;
}

void Matrix::set(std::initializer_list<double> vals){
  std::copy(vals.begin(), vals.end(), matrix);
}

unsigned Matrix::rows() const { return ROWS; }
unsigned Matrix::cols() const { return COLS; }

// below: body of inline functions needs to be in the header
// so we make these non-inline here.
//inline
double& Matrix::operator() (unsigned row, unsigned col)
{
    return matrix[COLS*row + col];
}

//inline
double Matrix::operator() (unsigned row, unsigned col) const
{
  return matrix[COLS*row + col];
}

bool Matrix::operator== (const Matrix& rhs) const
{
    // TODO!! Wrong!!
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
      double v = matrix[row*COLS + col];
      T(col, row) = v;
    }
  }
  return T;
}

double Matrix::determinant() const {
  double det=0.0;

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

double Matrix::minor(unsigned row, unsigned col) const {
  Matrix m = this->submatrix(row, col);
  return m.determinant();
}

double Matrix::cofactor(unsigned row, unsigned col) const {
  double m=minor(row, col);
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
  double dm = this->determinant();

  if (!this->isInvertible()) {
    return Matrix{0,0};
  } else {
    for (unsigned row=0; row<this->ROWS; ++row) {
      for (unsigned col=0; col<this->COLS; ++col) {
        double c = this->cofactor(row, col);
        M2(col,row) = c/dm;
      }
    }
  }
  return M2;
}

/****************

   TRANSFORMS (WAS Transform.cpp)

*****************/

Matrix& Matrix::translation(double x, double y, double z) {

    Matrix transform=identity();
    transform(0,3) = x;
    transform(1,3) = y;
    transform(2,3) = z;
    this->matrix = this->operator*(transform).matrix;

    return *this;
}

Matrix& Matrix::scaling(double t, double u, double v) {

  Matrix transform = identity();
  transform(0,0) = t;
  transform(1,1) = u;
  transform(2,2) = v;
  this->matrix = this->operator*(transform).matrix;
  return *this;
}

Matrix& Matrix::rotation_x(double radians) {

  double cosr = cos(radians);
  double sinr = sin(radians);

  Matrix transform = identity();

  transform(1,1) = cosr;
  transform(1,2) = -sinr;
  transform(2,1) = sinr;
  transform(2,2) = cosr;
  this->matrix = this->operator*(transform).matrix;
  return *this;
}

Matrix& Matrix::rotation_y(double radians) {
  double cosr = cos(radians);
  double sinr = sin(radians);

  Matrix transform = identity();

  transform(0,0) = cosr;
  transform(0,2) = sinr;
  transform(2,0) = -sinr;
  transform(2,2) = cosr;
  this->matrix = this->operator*(transform).matrix;
  return *this;
}

Matrix& Matrix::rotation_z(double radians) {
  double cosr = cos(radians);
  double sinr = sin(radians);

  Matrix transform = identity();

  transform(0,0) = cosr;
  transform(0,1) = -sinr;
  transform(1,0) = sinr;
  transform(1,1) = cosr;
  this->matrix = this->operator*(transform).matrix;
  return *this;
}

Matrix& Matrix::shearing(double xy, double xz, double yx, double yz, double zx, double zy) {

  Matrix transform = identity();

  transform(0,1) = xy;
  transform(0,2) = xz;
  transform(1,0) = yx;
  transform(1,2) = yz;
  transform(2,0) = zx;
  transform(2,1) = zy;
  this->matrix = this->operator*(transform).matrix;
  return *this;
}

/****************

   NON-MEMBERS

*****************/

Matrix identity() {
  return Matrix(4,4,{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1});
}

// chapter 7, view transformations
Matrix view_transform(const Point& from, const Point& to, const Vector& up) {

    Vector forward = normalize(to - from);

    auto left = forward.cross(normalize(up));
    auto true_up = left.cross(forward);

    Matrix orientation(4,4,
    {
         left.x(),     left.y(),     left.z(),    0.0,
         true_up.x(),  true_up.y(),  true_up.z(), 0.0,
        -forward.x(), -forward.y(), -forward.z(), 0.0,
         0.0,          0.0,          0.0,         1.0
    }

    );

    return orientation.translation(-from.x(), -from.y(), -from.z());
    //return orientation.translation(1,2,3);
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
