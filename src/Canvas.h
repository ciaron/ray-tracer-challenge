#ifndef CANVAS_H
#define CANVAS_H

#include "Color.h"
#include <vector>

using namespace std;

class Canvas {
  protected:
    int w, h;

  public:
    Canvas(int w, int h);
    int width() const;
    int height() const;
    vector<Color> pixels;

    Color pixelAt(int x, int y) const;
    void setPixel(int x, int y, Color c);
};
#endif
