#include "Util.h"
#include "Matrix.h"
#include "Ray.h"
#include "Point.h"
#include "Vector.h"
#include "Sphere.h"

#include "Color.h"
#include "Canvas.h"

using namespace std;
int Shape::count=0;

int main(){
    Point ray_origin(0,0,-5);
    float wall_z = 10.0;
    float wall_size = 7.0;
    int canvas_pixels = 100;
    float pixel_size = wall_size/canvas_pixels;
    float half = wall_size/2.0;  // describes minimum and maximum x and y coordinates of the wall

    Canvas c(canvas_pixels, canvas_pixels);
    Color cl(1, 0.0, 0.0); // red
    Sphere shape;

    // shrink sphere on y axis.
    //Matrix t = identity().scaling(1, 0.5, 1);
    //  shape.set_transform(t);

    // shrink sphere on x axis.
    //Matrix t = identity().scaling(0.5, 1, 1);
    shape.set_transform(identity().scaling(0.5, 1, 1));

    // shrink and rotate
    //shape.set_transform(identity().rotation_z(M_PI / 4).scaling(0.5, 1, 1));

    // shrink and skew
    //shape.set_transform(identity().shearing(1, 0, 0, 0, 0, 0).scaling(0.5, 1, 1));

    for (int y=0; y<canvas_pixels; ++y) {
        // compute the world y coordinate (top = +half, bottom = -half)
        float world_y = half-pixel_size * y;

        for (int x=0; x<canvas_pixels; ++x) {
            // compute the world x coordinate (left = -half, right = +half)
            float world_x = -half + pixel_size * x;

            // describe the point on the wall that the ray will target
            Point position = Point(world_x, world_y, wall_z);
            Vector v = (position-ray_origin);
            v.normalize();
            Ray r(ray_origin, v);

            auto xs = r.intersect(shape);
            //cout >> hit(xs);
            if(hit(xs)){
                c.setPixel(x,y,cl);
            }
        }
    }

    //c.setPixel(x, y, cl);
    string ppm = canvas_to_ppm(c);
    cout << ppm; // read with ""./chapter5 | feh -""
    return 0;
}
