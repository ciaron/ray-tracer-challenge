#ifndef TUPLE_H
#define TUPLE_H

class Tuple {

protected:
    float xval,yval,zval,wval;

  public:
    //Tuple();
    Tuple(float x, float y, float z, float w);

    bool operator ==(const Tuple a);
    Tuple operator +(const Tuple a);
    Tuple operator -(); // unary -
    Tuple operator -(const Tuple a);
    Tuple operator *(const float d);
    Tuple operator /(const float d);

    float x() const;
    float y() const;
    float z() const;
    float w() const;

    bool isPoint();
    bool isVector();

    bool isEqual(Tuple t);

    //float magnitude();  // done in Vector
    //Tuple normalize(); // done in Vector
    float dot(Tuple t);
    Tuple cross(Tuple t);
};

#endif
