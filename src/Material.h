#ifndef MATERIAL_H
#define MATERIAL_H

#include "Color.h"
#include <iostream>

using namespace std;

class Material {

  private:
    double ambient;

  public:
    Color color;
    double diffuse;
    double specular;
    double shininess;

    Material() :ambient{0.1}, color{Color(1,1,1)}, diffuse{0.9}, specular{0.9}, shininess{200.0} { }

    bool operator== (const Material& rhs) const {
        return (rhs.color == this->color && equal(rhs.getAmbient(), this->getAmbient()) && equal(rhs.diffuse, this->diffuse) && equal(rhs.specular, this->specular) && equal(rhs.shininess, this->shininess));

    }

    double getAmbient() const {
        return ambient;
    }

    void setAmbient(float a) {
        ambient = a;
    }
};

ostream& operator<<(ostream& os, const Material& rhs)
{
    // simply print the matrix dimensions for now. TODO
    //os << rhs.ROWS << "x" << rhs.COLS;
    os << endl;
    os << rhs.getAmbient() << " ";
    os << endl;
    return os;
}

#endif
