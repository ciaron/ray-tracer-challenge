#ifndef TUPLE_H
#define TUPLE_H

class Tuple {

  private:
    float xval,yval,zval,wval;

  public:
    Tuple(float x, float y, float z, float w);

    Tuple operator + (Tuple b);
    Tuple operator - (Tuple b);

    float x();
    float y();
    float z();
    float w();

    bool isPoint();
    bool isVector();

    bool isEqual(Tuple t);
};

#endif
