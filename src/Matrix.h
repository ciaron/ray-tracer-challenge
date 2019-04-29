#ifndef MATRIXH
#define MATRIX_H

#include<vector>

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

  unsigned rows() const;
  unsigned cols() const;
};

#endif
