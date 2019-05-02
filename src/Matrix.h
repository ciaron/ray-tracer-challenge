#ifndef MATRIXH
#define MATRIX_H

#include "Tuple.h"
#include <vector>
#include <iostream>

using namespace std;

// function "minor" conflicts with a system macro?
#ifdef minor
# undef minor
#endif

class Matrix {

private:
  unsigned ROWS,COLS;
  float *matrix;

public:
  Matrix(unsigned rows, unsigned cols);
  Matrix(unsigned rows, unsigned cols, std::initializer_list<float> data); // constructor including initializer_list
  
  void set(float *vals);
  void set(std::initializer_list<float>);

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

  Matrix transpose() const;
  float determinant() const;
  Matrix submatrix(unsigned row, unsigned col) const; // return a matrix with given row and column removed
  float minor(unsigned row, unsigned col) const;
  float cofactor(unsigned row, unsigned col) const;
  bool isInvertible() const;
  Matrix inverse() const;

  unsigned rows() const;
  unsigned cols() const;
};

// non-member function
Tuple operator*(const Tuple& t, const Matrix& A);

#endif
