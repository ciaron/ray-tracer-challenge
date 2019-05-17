#include "Matrix.h"
#include "Color.h"
#include "Canvas.h"
#include <iostream>
#include <cmath>

// return rotation matrix for a given hour
Matrix rot(int hour) {
  double h_rads = M_PI/6; // radians for one hour
  return identity().rotation_y(hour * h_rads);
}

int main(){

  double radius = 3*1000/8.0;
  Canvas c(1000, 1000);
  Color cl(1, 0.8, 0.6);

  Point centre(0,0,0);
  Point hour(0,0,1);  // initialize at 12

  Point current(0,0,0);
  for (int n=1; n<=12; ++n) {
    current = rot(n) * hour;
    c.setPixel(radius*current.x()+500, radius*current.z()+500, cl);
  }

  string ppm = canvas_to_ppm(c);
  cout << ppm; // read with ""./chapter4 | feh -""
  return 0;
}
