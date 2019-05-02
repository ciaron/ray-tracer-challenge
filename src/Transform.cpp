#include "Transform.h"
#include "Matrix.h"

using namespace std;

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
