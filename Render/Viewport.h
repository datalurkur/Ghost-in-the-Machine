#ifndef VIEWPORT_H
#define VIEWPORT_H

struct Viewport {
    int x, y, w, h;
    
    inline Viewport(): x(0), y(0), w(0), h(0) {}
    inline Viewport(int nX, int nY, int nW, int nH): x(nX), y(nY), w(nW), h(nH) {}

    inline Viewport& operator=(const Viewport &other) {
        x = other.x;
        y = other.y;
        w = other.w;
        h = other.h;
        return *this;
    }
};

#endif
