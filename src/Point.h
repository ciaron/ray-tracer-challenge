#ifndef POINT_H
#define POINT_H

#include "Tuple.h"

 inline Tuple point(float x, float y, float z) {
     return Tuple(x, y, z, 1.0);
}

// class Point : public Tuple {
// private:
//   float pxval,pyval,pzval,pwval;
//
//   Point(float w=1.0) {
//     // Tuple::xval=x;
//     // Tuple::yval=y;
//     // Tuple::zval=z;
//     // Tuple::wval=1.0;
//     Tuple(x,y,z,1.0);
//     // pxval=x;
//     // pyval=y;
//     // pzval=z;
//     // pwval=1.0;
//   }
// }

#endif
