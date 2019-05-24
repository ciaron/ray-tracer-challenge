#ifndef CAMERA_H
#define CAMERA_H

#include <cmath>
#include "Matrix.h"

class Camera {

public:
    int hsize;
    int vsize;
    double field_of_view;
    Matrix transform;

    Camera(int hsize, int vsize, double field_of_view) : hsize{hsize}, vsize{vsize}, field_of_view{field_of_view}, transform{identity()} {


    };

    Camera() : Camera(160, 120, M_PI/2) {}

};

// ostream& operator<<(ostream& os, const Shape& rhs) {
//     os << "Shape: " << rhs.id() << " ";
//     return os;
// }

#endif
