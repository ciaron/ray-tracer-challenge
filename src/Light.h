#ifndef LIGHT_H
#define LIGHT_H

#include "Point.h"
#include "Vector.h"
#include "Color.h"

class Pointlight {

  public:
    Point position;
    Color intensity;
    Pointlight(Point p, Color c) : position{p},intensity{c} {}

};

Color lighting(const Material& m, const Pointlight& light, const Point& position, const Vector& eyev, const Vector& normalv) {
    // combine the surface color with the light's color/intensity
    Color effective_color = m.color * light.intensity;

    // find the direction to the light source
    Vector lightv = normalize(light.position - position);

    // compute the ambient contribution
    Color ambient = effective_color * m.ambient;

    // light_dot_normal represents the cosine of the angle between the​
    // light vector and the normal vector. A negative number means the​
    // light is on the other side of the surface.
    double light_dot_normal = lightv.dot(normalv);

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

#endif
