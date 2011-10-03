#ifndef MATERIAL_H
#define MATERIAL_H

#include <Render/Texture.h>

class Material {
public:
    Material();
    virtual ~Material();

    void setColor(float r, float g, float b, float a);
    void setTexture(Texture *texture);

    void enable();
    void disable();

private:
    float _r, _g, _b, _a;
    Texture *_texture;
};

#endif
