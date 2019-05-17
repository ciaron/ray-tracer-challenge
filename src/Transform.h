// #ifndef TRANSFORM_H
// #define TRANSFORM_H
// #include "Matrix.h"
//
// using namespace std;
//
// class Transform : public Matrix {
//   private:
//     Matrix t;
//
//   public:
//
//     // call the appropriate Matrix constructor, for a 4x4 identity matrix
//     Transform() : Matrix{4,4,{
//       1,0,0,0,
//       0,1,0,0,
//       0,0,1,0,
//       0,0,0,1 }} {  };
//
//     Transform& translation(double x, double y, double z);
//     Transform& scaling(double t, double u, double v);
//     Transform& rotation_x(double radians);
//     Transform& rotation_y(double radians);
//     Transform& rotation_z(double radians);
//     Transform& shearing(double xy, double xz, double yx, double yz, double zx, double zy);
// };
//
// #endif
