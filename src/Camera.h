#ifndef CAMERA_H
#define CAMERA_H

#include <cmath>
#include "Matrix.h"
#include "Ray.h"

class Camera {

public:
    int hsize;
    int vsize;
    double field_of_view;
    double pixel_size;
    double half_width;
    double half_height;

    Matrix transform;

    Camera(int hsize, int vsize, double field_of_view) : hsize{hsize}, vsize{vsize}, field_of_view{field_of_view}, transform{identity()} {
      double half_view = tan(field_of_view / 2.0);
      double aspect = (double)hsize / (double)vsize;

      if (aspect >= 1.0) {
          half_width = half_view;
          half_height = half_view / aspect;
      } else {
        half_width = half_view * aspect;
        half_height = half_view;
      }

      pixel_size = half_width*2.0 / hsize;

    };

    Camera() : Camera(160, 120, M_PI/2) {}

};

Ray ray_for_pixel(Camera c, int px, int py) {
    // the offset from the edge of the canvas to the pixel centre
    double xoffset = (px + 0.5) * c.pixel_size;
    double yoffset = (py + 0.5) * c.pixel_size;
    // the untransformed coordinates of the pixel in world space
    // (remember that the camera looks toward -x so +x is to the *left* )
    double world_x = c.half_width - xoffset;
    double world_y = c.half_height - yoffset;

    // using the camera matrix, transform the canvas point and the origin,
    // and then compute the ray's direction vector;
    // Remember that the canvas is at z=-1

    Point pixel = c.transform.inverse() * Point(world_x, world_y, -1);
    Point origin = c.transform.inverse() * Point(0,0,0);
    Vector direction = normalize(pixel - origin);
    return Ray(origin, direction);
}

// ostream& operator<<(ostream& os, const Shape& rhs) {
//     os << "Shape: " << rhs.id() << " ";
//     return os;
// }

#endif
