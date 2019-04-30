#ifndef TUPLE_H
#define TUPLE_H

#include <iostream>
using namespace std;

class Tuple {

protected:
    float xval,yval,zval,wval;

  public:
    //Tuple();
    Tuple(float x, float y, float z, float w);

    bool operator ==(const Tuple a) const;
    Tuple operator +(const Tuple a);
    Tuple operator -(); // unary -
    Tuple operator -(const Tuple a);
    Tuple operator *(const float d);
    Tuple operator /(const float d);

    float& operator() (unsigned idx);        // Subscript operators often come in pairs
    float  operator() (unsigned idx) const;  // Subscript operators often come in pairs

    friend ostream& operator<<(ostream& os, const Tuple& rhs); // friend has access to class internals

    float x() const;
    float y() const;
    float z() const;
    float w() const;
    float& x();
    float& y();
    float& z();
    float& w();

    bool isPoint();
    bool isVector();

    bool isEqual(Tuple t);

    //float magnitude();  // done in Vector
    //Tuple normalize(); // done in Vector
    float dot(Tuple t);
    Tuple cross(Tuple t);
};

#endif
