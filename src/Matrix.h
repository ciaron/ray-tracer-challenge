#ifndef MATRIXH
#define MATRIX_H

#include<vector>

using namespace std;

class Matrix {

private:
  int ROWS{0};
  int COLS{0};
  float *m;


public:
  Matrix(int rows, int cols);
  int rows() const;
  int cols() const;
  inline float& at(int r, int c) const {
    return m[COLS*r + c];
  }
};

#endif
