#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <string>
#include "Color.h"

class Canvas {
  protected:
    int w, h;

  public:
    Canvas(int w, int h);
    int width() const;
    int height() const;
    std::vector<Color> pixels;

    Color pixelAt(int x, int y) const;
    void setPixel(int x, int y, Color c);
};

inline std::string canvas_to_ppm(Canvas c) {
    std::string header = "P3\n" + std::to_string(c.width()) + " " + std::to_string(c.height()) + "\n255\n";
    std::string pixeldata;

    for (int y=0; y<c.height(); y++) {
        for (int x=0; x<c.width(); x++) {
            Color cl = c.pixelAt(x, y);
            int r = std::round(cl.red()*255);
            int g = std::round(cl.green()*255);
            int b = std::round(cl.blue()*255);

            // clamping to range 0..255
            r=r>255?255:r; r=r<0?0:r;
            g=g>255?255:g; g=g<0?0:g;
            b=b>255?255:b; b=b<0?0:b;

            pixeldata += std::to_string(r) + " " + std::to_string(g) + " " + std::to_string(b) + " ";
        }
        pixeldata += "\n";
    }

    return header + pixeldata;
}

#endif
