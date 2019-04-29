#include "Matrix.h"
using namespace std;

Matrix::Matrix(int rows, int cols, float m[]) : ROWS{rows}, COLS{cols}, matrix{*m} { }

int Matrix::rows() const { return ROWS; }
int Matrix::cols() const { return COLS; }
