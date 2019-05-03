#include "Transform.h"
#include "Matrix.h"

using namespace std;
#include <cmath>

void Transform::translation(float x, float y, float z) {
    this->operator()(0,3) = x;
    this->operator()(1,3) = y;
    this->operator()(2,3) = z;
}

void Transform::scaling(float t, float u, float v) {
  this->operator()(0,0) = t;
  this->operator()(1,1) = u;
  this->operator()(2,2) = v;
}

void Transform::rotation_x(float radians) {
  float cosr = cos(radians);
  float sinr = sin(radians);

  this->operator()(1,1) = cosr;
  this->operator()(1,2) = -sinr;
  this->operator()(2,1) = sinr;
  this->operator()(2,2) = cosr;
}

void Transform::rotation_y(float radians) {
  float cosr = cos(radians);
  float sinr = sin(radians);

  this->operator()(0,0) = cosr;
  this->operator()(0,2) = sinr;
  this->operator()(2,0) = -sinr;
  this->operator()(2,2) = cosr;
}

void Transform::rotation_z(float radians) {
  float cosr = cos(radians);
  float sinr = sin(radians);

  this->operator()(0,0) = cosr;
  this->operator()(0,1) = -sinr;
  this->operator()(1,0) = sinr;
  this->operator()(1,1) = cosr;
}
