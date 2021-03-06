#include "Tuple.h"
#include "Vector.h"
#include "Util.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Tuple::Tuple(double x, double y, double z, double w)
    :xval{x}, yval {y}, zval{z}, wval{w}
{
}

bool Tuple::operator==(Tuple b) const {
    return ( equal(this->x(), b.x()) && equal(this->y(), b.y()) && equal(this->z(), b.z()) && equal(this->w(), b.w()) );
}

Tuple Tuple::operator+(Tuple b){
    return Tuple( this->x() + b.x(), this->y() + b.y(), this->z() + b.z(), this->w() + b.w() );
}

Tuple Tuple::operator-(){
    return Tuple( -this->x(), -this->y(), -this->z(), -this->w());
}

Tuple Tuple::operator-(Tuple b){
    return Tuple( this->x() - b.x(), this->y() - b.y(), this->z() - b.z(), this->w() - b.w() );
}

Tuple Tuple::operator *(const double d){
    return Tuple(this->x()*d, this->y()*d, this->z()*d, this->w()*d);
}

Tuple Tuple::operator /(const double d) {
    return Tuple(this->x()/d, this->y()/d, this->z()/d, this->w()/d);
}

// operator() lets us access Tuple elements by index number
double& Tuple::operator() (unsigned idx)
{
  switch (idx) {
    case 0:
      return this->x();
      break;
    case 1:
      return this->y();
      break;
    case 2:
      return this->z();
      break;
    case 3:
      return this->w();
      break;
    default:
      return this->x();
  }
}

double Tuple::operator() (unsigned idx) const
{
  switch (idx) {
    case 0:
      return this->x();
      break;
    case 1:
      return this->y();
      break;
    case 2:
      return this->z();
      break;
    case 3:
      return this->x();
      break;
  }
  return -1;
}

// const guarantees the function doesn't change anything.
double Tuple::x() const { return xval; }
double Tuple::y() const { return yval; }
double Tuple::z() const { return zval; }
double Tuple::w() const { return wval; }

double& Tuple::x() { return xval; }
double& Tuple::y() { return yval; }
double& Tuple::z() { return zval; }
double& Tuple::w() { return wval; }

bool Tuple::isPoint() {
    return (equal(wval, 1.0)) ? true : false;
}

bool Tuple::isVector() {
    return (equal(wval, 0.0)) ? true : false;
}

bool Tuple::isEqual(Tuple t) {
    return (equal(xval, t.x()) && equal(yval, t.y()) && equal(zval, t.z()));
}

// done in Vector
// double Tuple::magnitude(){
//     return sqrt(xval*xval + yval*yval + zval*zval + wval*wval);
// }

// done in Vector now
// Tuple Tuple::normalize(){
//     double m = this->magnitude();
//     return Tuple(xval/m, yval/m, zval/m, wval/m);
// }

double Tuple::dot(const Tuple& a) const {
    return this->x() * a.x() +
           this->y() * a.y() +
           this->z() * a.z() +
           this->w() * a.w();
}

Tuple Tuple::cross(const Tuple& a) const {
    return Vector(
            this->y() * a.z() - this->z() * a.y(),
            this->z() * a.x() - this->x() * a.z(),
            this->x() * a.y() - this->y() * a.x()
    );
}

// this must be declared outside the class. See
// https://stackoverflow.com/questions/10744787/operator-must-take-exactly-one-argument
// https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=vs-2019
ostream& operator<<(ostream& os, const Tuple& rhs)
{
    // simply print the matrix dimensions for now. TODO
    os << "[ " << rhs.x() << " " << rhs.y() << " " << rhs.z() << " " << rhs.w() << " ]";
    return os;
}
