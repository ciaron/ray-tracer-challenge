#ifndef MATRIXH
#define MATRIX_H

#include<vector>
#include <iostream>

using namespace std;

class Matrix {

private:
  unsigned ROWS,COLS;
  float matrix[];

public:
  Matrix(unsigned rows, unsigned cols, float m[]);

  // see https://isocpp.org/wiki/faq/operator-overloading#matrix-subscript-op
  float& operator() (unsigned row, unsigned col);        // Subscript operators often come in pairs
  float  operator() (unsigned row, unsigned col) const;  // Subscript operators often come in pairs

  friend ostream& operator<<(ostream& os, const Matrix& rhs); // friend has access to class internals

  bool operator== (const Matrix& rhs) const;
  bool operator!= (const Matrix& rhs) const;

  unsigned rows() const;
  unsigned cols() const;
};

#endif
