#ifndef SPHERE_H
#define SPHERE_H
#include "Shape.h"
#include "Vector.h"
#include "Util.h"
#include "Material.h"

class Sphere : public Shape {

public:
    Material material;

    Sphere() { }

    Vector normal_at(const Point& world_point) {
      Point object_point = (this->get_transform().inverse()) * world_point;
      Vector object_normal = (object_point - Point(0,0,0));
      Vector world_normal = (this->get_transform().inverse().transpose()) * object_normal;
      world_normal.w() = 0;

      return normalize(world_normal);
    }

    bool operator==(Sphere rhs) const {
     return (rhs.id() == this->id());
    }

    void updateMaterial(double ambient) {
        //cout << "Sphere AMBIENT BEFORE " << material.getAmbient() << endl;

        material.setAmbient(ambient);
        //cout << "Sphere AMBIENT after " << material.getAmbient() << endl;
    }
};

ostream& operator<<(ostream& os, const Sphere& rhs)
{
    // simply print the matrix dimensions for now. TODO
    //os << rhs.ROWS << "x" << rhs.COLS;
    os << endl;
    os << rhs.id() << " ";
    os << endl;
    return os;
}
#endif
