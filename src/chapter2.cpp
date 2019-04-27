#include <iostream>
#include <math.h>
#include "Point.h"
#include "Vector.h"
#include "Util.h"
#include "Color.h"
#include "Canvas.h"

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
    Vector velocity = {proj.velocity  + env.gravity + env.wind};
    return Projectile{pos,velocity};
}

int main() {

    Canvas c{900,550};
    Color cl(1, 0.8, 0.6);

    Vector gravity{0, -0.1, 0};
    Vector wind{-0.01, 0, 0};
    Environment env = Environment{gravity, wind};

    Point start{0, 1, 0};
    Vector velocity{1, 1.8, 0};

    // TODO normalise vector in place
    velocity=velocity.normalize();

    velocity *= 11.25;

    Projectile proj = Projectile{start, velocity};

    //cout << "Projectile position: " << proj.position.x() << " " << proj.position.y() << " " << proj.position.z() << "\n";
    //cout << "Projectile velocity: " << proj.velocity.x() << " " << proj.velocity.y() << " " << proj.velocity.z() << "\n";

    while (proj.position.y() >= 0.0) {
        //cout << "Projectile position: " << proj.position.x() << " " << proj.position.y() << " " << proj.position.z() << "\n";
        proj = tick(env, proj);
        int x = (int) proj.position.x();
        int y = (int) proj.position.y();
        if (y>549 || x>899 || y<0 || x<0) { // TODO: move this error checking into Canvas
          //cout << "Halp! " << x << " " << y << endl;
        } else {
          c.setPixel(900-x,550-y,cl);
        }
    }

    string ppm = canvas_to_ppm(c);
    cout << ppm;

}
