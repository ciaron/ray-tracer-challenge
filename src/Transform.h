#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "Matrix.h"

using namespace std;

class Transform : public Matrix {
  private:
    Matrix t;

  public:

    // call the appropriate Matrix constructor, for a 4x4 identity matrix
    Transform() : Matrix{4,4,{
      1,0,0,0,
      0,1,0,0,
      0,0,1,0,
      0,0,0,1 }} {  };

    Transform& translation(float x, float y, float z);
    Transform& scaling(float t, float u, float v);
    Transform& rotation_x(float radians);
    Transform& rotation_y(float radians);
    Transform& rotation_z(float radians);
    Transform& shearing(float xy, float xz, float yx, float yz, float zx, float zy);
};

#endif
