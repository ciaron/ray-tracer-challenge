#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "Matrix.h"

using namespace std;

class Transform : public Matrix {
  private:
    Matrix t;

  public:

    // call the appropriate Matrix constructor
    Transform() : Matrix{4,4,{
      1,0,0,0,
      0,1,0,0,
      0,0,1,0,
      0,0,0,1 }} {  };

    void translation(float x, float y, float z);
    void scaling(float t, float u, float v);
    void rotation_x(float radians);
    void rotation_y(float radians);
    void rotation_z(float radians);
};

#endif
