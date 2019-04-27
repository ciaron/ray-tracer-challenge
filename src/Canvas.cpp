#include "Canvas.h"
#include <iostream>

Canvas::Canvas(int width, int height)
    :w{width}, h{height}, pixels(w*h, Color(0.0, 0.0, 0.0))
{

}

int Canvas::width() const { return w; }
int Canvas::height() const { return h; }

Color Canvas::pixelAt(int x, int y) const {
    return pixels[y*w + x];
}

void Canvas::setPixel(int x, int y, Color c) {
  // set pixel if x,y coordinates are valie
  if ( y>h-1 || x>w-1 || y<0 || x<0) {
    // pass
  } else {
    pixels[y*w+x] = c;
  }
}
