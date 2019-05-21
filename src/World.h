#ifndef WORLD_H
#define WORLD_H

#include "Sphere.h"
#include "Material.h"
#include "Point.h"
#include "Light.h"
#include "Ray.h"
#include "Intersection.h"

#include <iostream>
#include <algorithm>    // std::sort

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

    vector<Sphere> spheres() {
      return _spheres;
    }

    Pointlight light() {
        return _light;
    }

    bool contains(const Sphere& other) {
      // world contains the sphere if tranforms and materials match. Centre and radius always match.
      bool FOUND=false;
      for (Sphere s : _spheres) {
        if (s.material==other.material  &&
            s.get_transform() == other.get_transform()

        ) FOUND=true;
      }
      return FOUND;
    }

    vector<Intersection> intersect(const Ray& ray) const {
      // loop over all objects in the scene (spheres for now)
      //vector<Intersection> xs1 = r1.intersect(s);

      vector<Intersection> all_xs;
      for (Sphere s : _spheres) {
        vector<Intersection> xs = ray.intersect(s);
        if (xs.size()) {
          for (auto x : xs){
            all_xs.push_back(x);
          }
        }
      }

      //sort all_xs before returning
      sort(all_xs.begin(), all_xs.end(), compareIntersection);
      return all_xs;
    }
};

#endif
