#include <iostream>
#include <math.h>
#include "Point.h"
#include "Vector.h"

using namespace std;

struct Environment {
    Vector gravity;
    Vector wind;
};

struct Projectile {
    Point p;
    Vector v;
};

int main() {

    Environment env = Environment{Vector{0,-0.1,0}, Vector{-0.01,0,0}};
    Vector v {1,1,0};
    Projectile proj = Projectile{Point{0,1,0}, v.normalize()};
    cout << "Gravity: " << env.gravity.x() << " " << env.gravity.y() << " " << env.gravity.z() << "\n";
}
