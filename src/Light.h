#ifndef LIGHT_H
#define LIGHT_H

#include "Point.h"
#include "Vector.h"
#include "Color.h"

class Pointlight {

  public:
    Point position;
    Color intensity;

    Pointlight() : position{Point(-10,10,-10)},intensity{Color(1,1,1)} {}
    Pointlight(Point p, Color c) : position{p},intensity{c} {}

    bool operator==(const Pointlight& rhs) const {
        // two lights are equal if they have the same position and colour
        return (rhs.position == position && rhs.intensity == intensity);
    }
};

Color lighting(const Material& m, const Pointlight& light, const Point& position, const Vector& eyev, const Vector& normalv) {
    // combine the surface color with the light's color/intensity
    Color effective_color = m.color * light.intensity;

    // find the direction to the light source
    Vector lightv = normalize(light.position - position);

    // compute the ambient contribution
    Color ambient = effective_color * m.getAmbient();

    // light_dot_normal represents the cosine of the angle between the​
    // light vector and the normal vector. A negative number means the​
    // light is on the other side of the surface.
    double light_dot_normal = lightv.dot(normalv);

    // debugging
    // cout << "lightv" << lightv << endl;
    // cout << "normalv" << normalv << endl;
    // cout << "light_dot_normal" << light_dot_normal << endl;

    Color diffuse(0.0, 0.0, 0.0);
    Color specular(0.0, 0.0, 0.0);

    if (light_dot_normal < 0) {
        // diffuse and specular remain black
    } else {
        // compute the diffuse contribution
        diffuse = effective_color * m.diffuse * light_dot_normal;

        // reflect_dot_eye represents the cosine of the angle between the
        // reflection vector and the eye vector. A negative number means the
        // light reflects away from the eye
        //Vector reflectv = (lightv * -1.0).reflect(normalv);
        Vector reflectv = (lightv * -1.0).reflect(normalv);
        double reflect_dot_eye = reflectv.dot(eyev);

        if (reflect_dot_eye <= 0.0){
            specular = Color(0.0,0.0,0.0);
        } else {
            double factor = pow(reflect_dot_eye, m.shininess);
            specular = light.intensity * m.specular * factor;
        }
    }

    return ambient + diffuse + specular;//Color(0,0,0);
}

ostream& operator<<(ostream& os, const Pointlight& rhs)
{
    // simply print the matrix dimensions for now. TODO
    //os << rhs.ROWS << "x" << rhs.COLS;
    os << endl;
    os << " pointlight at " << rhs.position;
    os << endl;
    return os;
}

#endif
