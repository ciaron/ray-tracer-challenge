#ifndef TUPLE_H
#define TUPLE_H

#include <iostream>
using namespace std;

class Tuple {

protected:
    double xval,yval,zval,wval;

  public:
    //Tuple();
    Tuple(double x, double y, double z, double w);

    bool operator ==(const Tuple a) const;
    Tuple operator +(const Tuple a);
    Tuple operator -(); // unary -
    Tuple operator -(const Tuple a);
    Tuple operator *(const double d);
    Tuple operator /(const double d);

    double& operator() (unsigned idx);        // Subscript operators often come in pairs
    double  operator() (unsigned idx) const;  // Subscript operators often come in pairs

    friend ostream& operator<<(ostream& os, const Tuple& rhs); // friend has access to class internals

    double x() const;
    double y() const;
    double z() const;
    double w() const;
    double& x();
    double& y();
    double& z();
    double& w();

    bool isPoint();
    bool isVector();

    bool isEqual(Tuple t);

    //double magnitude();  // done in Vector
    //Tuple normalize(); // done in Vector
    double dot(const Tuple& t) const;
    Tuple cross(const Tuple& t) const;
};

#endif
