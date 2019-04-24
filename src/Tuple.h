#ifndef TUPLE_H
#define TUPLE_H

class Tuple {

  protected:
    float xval,yval,zval,wval;

  public:
    //Tuple();
    Tuple(float x, float y, float z, float w);

    Tuple operator +(const Tuple a);
    Tuple operator -(); // unary -
    Tuple operator -(const Tuple a);
    Tuple operator *(const float d);
    Tuple operator /(const float d);

    float x();
    float y();
    float z();
    float w();

    bool isPoint();
    bool isVector();

    bool isEqual(Tuple t);

    float magnitude();
    Tuple normalize();
    float dot(Tuple t);
    Tuple cross(Tuple t);
};

#endif
