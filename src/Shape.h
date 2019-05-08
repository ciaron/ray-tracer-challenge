#ifndef SHAPE_H
#define SHAPE_H

#include "Matrix.h"

class Shape {

private:
    int _id;
    Matrix _transform;

public:
    static int count;

    Shape()
    {
        _transform = identity();
        _id = count;
        ++count;
    }

    int id() const { return _id; }

    Matrix get_transform() const {
        return _transform;
    }

    void set_transform(const Matrix& m) {
        _transform = m;
    }

};

#endif
