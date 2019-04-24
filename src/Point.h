#ifndef POINT_H
#define POINT_H

#include "Tuple.h"

inline Tuple point(float x, float y, float z) {
    return Tuple(x, y, z, 1.0);
}

#endif
