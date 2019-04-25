#include <iostream>
#include <math.h>
#include "Point.h"
#include "Vector.h"
#include "Util.h"

using namespace std;

struct Environment {
    Vector gravity;
    Vector wind;
};

struct Projectile {
    Point position;
    Vector velocity;
};

Projectile tick(Environment env, Projectile proj) {
    Point pos = proj.position + proj.velocity;
    Vector velocity = proj.velocity + env.gravity + env.wind;
    return Projectile{pos,velocity};
}

int main() {

    Environment env = Environment{Vector{0,-0.1,0}, Vector{-0.01,0,0}};
    Vector v {1,1,0};
    Projectile proj = Projectile{Point{0,1,0}, v.normalize()};

    cout << "Projectile position: " << proj.position.x() << " " << proj.position.y() << " " << proj.position.z() << "\n";
    cout << "Projectile velocity: " << proj.velocity.x() << " " << proj.velocity.y() << " " << proj.velocity.z() << "\n";

    proj = tick(env, proj);

    //cout << "Gravity: " << env.gravity.x() << " " << env.gravity.y() << " " << env.gravity.z() << "\n";
    cout << "Projectile position: " << proj.position.x() << " " << proj.position.y() << " " << proj.position.z() << "\n";
    cout << "Projectile velocity: " << proj.velocity.x() << " " << proj.velocity.y() << " " << proj.velocity.z() << "\n";
}
