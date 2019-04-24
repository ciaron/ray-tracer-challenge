#ifndef VECTOR_H
#define VECTOR_H

#include "Tuple.h"

inline Tuple vector(float x, float y, float z) {
    return Tuple(x, y, z, 0.0);
}

#endif
