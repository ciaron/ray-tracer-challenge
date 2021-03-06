#ifndef MATERIAL_H
#define MATERIAL_H

#include "Color.h"
#include <iostream>

using namespace std;

class Material {

  private:


  public:
    Color color;
    double ambient;
    double diffuse;
    double specular;
    double shininess;

    Material() :color{Color(1,1,1)}, ambient{0.1}, diffuse{0.9}, specular{0.9}, shininess{200.0} { }

    bool operator== (const Material& rhs) const {
        return (rhs.color == this->color && equal(rhs.ambient, this->ambient)  && equal(rhs.diffuse, this->diffuse) && equal(rhs.specular, this->specular) && equal(rhs.shininess, this->shininess));

    }

    // double getAmbient() const {
    //     return ambient;
    // }
    //
    // void setAmbient(float a) {
    //     ambient = a;
    // }
    //Getter

// double ambient() const
// {
//     return _ambient;
// }
//
// //Setter (C2556)
// double& ambient(double a)
// {   _ambient = a;
//     return _ambient;
// }

};

ostream& operator<<(ostream& os, const Material& rhs)
{
    // simply print the matrix dimensions for now. TODO
    //os << rhs.ROWS << "x" << rhs.COLS;
    os << endl;
    os << rhs.ambient << " ";
    os << endl;
    return os;
}

#endif
