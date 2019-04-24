#include "Tuple.h"
#include "Vector.h"
#include "Util.h"

#include <cmath>

// Tuple::Tuple(){
//
// }

Tuple::Tuple(float x=0.0, float y=0.0, float z=0.0, float w=0.0) {
    xval=x;
    yval=y;
    zval=z;
    wval=w;
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

Tuple Tuple::operator *(const float d){
    return Tuple(this->x()*d, this->y()*d, this->z()*d, this->w()*d);
}

Tuple Tuple::operator /(const float d) {
    return Tuple(this->x()/d, this->y()/d, this->z()/d, this->w()/d);
}


float Tuple::x() { return xval; }
float Tuple::y() { return yval; }
float Tuple::z() { return zval; }
float Tuple::w() { return wval; }

bool Tuple::isPoint() {
    return (equal(wval, 1.0)) ? true : false;
}

bool Tuple::isVector() {
    return (equal(wval, 0.0)) ? true : false;
}

bool Tuple::isEqual(Tuple t) {
    return equal(xval, t.x()) && equal(yval, t.y()) && equal(zval, t.z());
}

float Tuple::magnitude(){
    return sqrt(xval*xval + yval*yval + zval*zval + wval*wval);
}

Tuple Tuple::normalize(){
    float m = this->magnitude();
    return Tuple(xval/m, yval/m, zval/m, wval/m);
}

float Tuple::dot(Tuple a) {
    return this->x() * a.x() +
           this->y() * a.y() +
           this->z() * a.z() +
           this->w() * a.w();

}

Tuple Tuple::cross(Tuple a) {
    return vector(
            this->y() * a.z() - this->z() * a.y(),
            this->z() * a.x() - this->x() * a.z(),
            this->x() * a.y() - this->y() * a.x()
    );

}
