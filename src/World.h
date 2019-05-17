#ifndef WORLD_H
#define WORLD_H

#include "Sphere.h"
#include "Material.h"
#include "Point.h"
#include "Light.h"

#include <iostream>

using namespace std;

class World {

private:
    vector<Sphere> _spheres;
    Pointlight _light;

public:

    World() {
        _light = Pointlight(Point(-10,10,-10), Color(1,1,1));
        Material m1;
        m1.color = Color(0.8, 1.0, 0.6);
        m1.diffuse = 0.7;
        m1.specular = 0.2;

        Sphere s1, s2;

        s1.material = m1;

        s2.set_transform(identity().scaling(0.5, 0.5, 0.5));

        _spheres.push_back(s1);
        _spheres.push_back(s2);
    }

    Pointlight light() {
        return _light;
    }

};

// ostream& operator<<(ostream& os, const World& rhs)
// {
//     // simply print the matrix dimensions for now. TODO
//     //os << rhs.ROWS << "x" << rhs.COLS;
//     os << endl;
//     os << rhs.ambient << " ";
//     os << endl;
//     return os;
// }

#endif
