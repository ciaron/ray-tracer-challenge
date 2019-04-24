#ifndef TUPLE_H
#define TUPLE_H

class Tuple {

  private:
    float xval,yval,zval,wval;

  public:
    Tuple(float x, float y, float z, float w);

    float x();
    float y();
    float z();
    float w();

    bool isPoint();
    bool isVector();
};

#endif