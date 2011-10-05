#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL/SDL_opengl.h>

class ThreadedTextureFactory;

class Texture {
public:
    Texture();
    virtual ~Texture();

	void setup(const unsigned int frames = 1);

	void enable(const unsigned int frame = 0);
	void disable();

protected:
	GLuint *_ids;
	unsigned int _frames;

	friend class ThreadedTextureFactory;
};

#endif
