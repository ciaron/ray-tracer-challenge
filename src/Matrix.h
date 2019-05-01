#ifndef MATRIXH
#define MATRIX_H

#include "Tuple.h"
#include <vector>
#include <iostream>

using namespace std;

class Matrix {

private:
  unsigned ROWS,COLS;
  float *matrix;

public:
  Matrix(unsigned rows, unsigned cols);
  void set(float *vals);

  // see https://isocpp.org/wiki/faq/operator-overloading#matrix-subscript-op
  float& operator() (unsigned row, unsigned col);        // Subscript operators often come in pairs
  float  operator() (unsigned row, unsigned col) const;  // Subscript operators often come in pairs

  friend ostream& operator<<(ostream& os, const Matrix& rhs); // friend has access to class internals

  bool operator== (const Matrix& rhs) const;
  bool operator!= (const Matrix& rhs) const;

  //matrix-matrix multiply
  Matrix operator*(const Matrix& B);
  //matrix-tuple multiply
  Tuple operator*(const Tuple& b);

  // tuple-matrix multiply
  //Tuple operator*(const Tuple& b, const Matrix& A);

  //Matrix operator*(const Vector& v);
  //Matrix operator*(const Point& p);

  unsigned rows() const;
  unsigned cols() const;
};

// non-member function
Tuple operator*(const Tuple& t, const Matrix& A);

#endif
