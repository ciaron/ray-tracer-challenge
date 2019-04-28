#ifndef MATRIXH
#define MATRIX_H

#include<vector>

using namespace std;

class Matrix {

private:
  int ROWS{0};
  int COLS{0};
  float *matrix;
  //vector<vector<float> > matrix;

public:
  Matrix(int rows, int cols);
  int rows() const;
  int cols() const;

  inline float& at(int r, int c) const {
      return matrix[COLS*r + c];
  }

  inline void setRow(int row, float &r) {
    matrix[COLS*row] = r;  // offset pointer here TODO
  }

};

#endif
