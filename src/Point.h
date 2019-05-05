#ifndef POINT_H
#define POINT_H

#include "Tuple.h"

class Point : public Tuple {
public:
  Point(float x, float y, float z) :Tuple(x,y,z,1.0)
  {}

  // TODO duplicated code
  // Point operator+(Point b){
  //   return Point( this->x() + b.x(), this->y() + b.y(), this->z() + b.z() );
  // }

};

#endif
