//#include "Transform.h"
#include "Matrix.h"

using namespace std;
#include <cmath>

Matrix& Matrix::translation(float x, float y, float z) {

    Matrix transform=identity();
    transform(0,3) = x;
    transform(1,3) = y;
    transform(2,3) = z;
    this->matrix = this->operator*(transform).matrix;

    // directly setting, translation unaffected by rotation?????
    //cout << "TRANSLATE" << endl;
    // this->operator()(0,3) += x;
    // this->operator()(1,3) += y;
    // this->operator()(2,3) += z;

    return *this;
}

Matrix& Matrix::scaling(float t, float u, float v) {

  //cout << "SCALE" << endl;
  Matrix transform = identity();
  transform(0,0) = t;
  transform(1,1) = u;
  transform(2,2) = v;
  this->matrix = this->operator*(transform).matrix;
  return *this;
}

Matrix& Matrix::rotation_x(float radians) {

  //cout << "ROTATE_X" << endl;
  float cosr = cos(radians);
  float sinr = sin(radians);

  Matrix transform = identity();

  transform(1,1) = cosr;
  transform(1,2) = -sinr;
  transform(2,1) = sinr;
  transform(2,2) = cosr;
  this->matrix = this->operator*(transform).matrix;
  return *this;
}

Matrix& Matrix::rotation_y(float radians) {
  float cosr = cos(radians);
  float sinr = sin(radians);

  Matrix transform = identity();

  transform(0,0) = cosr;
  transform(0,2) = sinr;
  transform(2,0) = -sinr;
  transform(2,2) = cosr;
  this->matrix = this->operator*(transform).matrix;
  return *this;
}

Matrix& Matrix::rotation_z(float radians) {
  float cosr = cos(radians);
  float sinr = sin(radians);

  Matrix transform = identity();

  transform(0,0) = cosr;
  transform(0,1) = -sinr;
  transform(1,0) = sinr;
  transform(1,1) = cosr;
  this->matrix = this->operator*(transform).matrix;
  return *this;
}

Matrix& Matrix::shearing(float xy, float xz, float yx, float yz, float zx, float zy) {

  Matrix transform = identity();

  transform(0,1) = xy;
  transform(0,2) = xz;
  transform(1,0) = yx;
  transform(1,2) = yz;
  transform(2,0) = zx;
  transform(2,1) = zy;
  this->matrix = this->operator*(transform).matrix;
  return *this;}
