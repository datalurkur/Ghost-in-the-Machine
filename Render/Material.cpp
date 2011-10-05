#include <Render/Material.h>
#include <SDL/SDL_opengl.h>

Material::Material(): _r(1.0), _g(1.0), _b(1.0), _a(1.0), _texture(0) {
}

Material::~Material() {
}

void Material::setColor(float r, float g, float b, float a) {
    _r = r;
    _g = g;
    _b = b;
    _a = a;
}

void Material::setTexture(Texture *texture) {
    _texture = texture;
}

void Material::enable() {
    if(_texture) {
		_texture->enable();
    } else {
        glDisable(GL_TEXTURE_2D);
    }
    glColor4f(_r, _g, _b, _a);
}

void Material::disable() {
}