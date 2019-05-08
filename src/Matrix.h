#ifndef MATRIX_H
#define MATRIX_H

#include "Tuple.h"
#include "Point.h"
#include "Vector.h"
#include <vector>
#include <iostream>

//using namespace std; // bad practice in header files

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
  Matrix();

  void set(float *vals);
  void set(std::initializer_list<float>);

  // see https://isocpp.org/wiki/faq/operator-overloading#matrix-subscript-op
  float& operator() (unsigned row, unsigned col);        // Subscript operators often come in pairs
  float  operator() (unsigned row, unsigned col) const;  // Subscript operators often come in pairs

  friend ostream& operator<<(ostream& os, const Matrix& rhs); // friend has access to class internals

  bool operator== (const Matrix& rhs) const;
  bool operator!= (const Matrix& rhs) const;

  //matrix-matrix multiply
  Matrix operator*(const Matrix& B) const;

  //matrix-tuple multiply
  Tuple operator*(const Tuple& b) const;

  // TODO: duplicated code here:
  Point operator*(const Point& b) const;
  Vector operator*(const Vector& v) const;


  Matrix transpose() const;
  float determinant() const;
  Matrix submatrix(unsigned row, unsigned col) const; // return a matrix with given row and column removed
  float minor(unsigned row, unsigned col) const;
  float cofactor(unsigned row, unsigned col) const;
  bool isInvertible() const;
  Matrix inverse() const;

  unsigned rows() const;
  unsigned cols() const;

  //Matrix identity();
  // transformation matrices
  Matrix& translation(float x, float y, float z);
  Matrix& scaling(float t, float u, float v);
  Matrix& rotation_x(float radians);
  Matrix& rotation_y(float radians);
  Matrix& rotation_z(float radians);
  Matrix& shearing(float xy, float xz, float yx, float yz, float zx, float zy);

};

// non-member function
Tuple operator*(const Tuple& t, const Matrix& A);

Matrix identity();

#endif
