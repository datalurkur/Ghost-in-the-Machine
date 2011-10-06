#include <Base/Base.h>
#include <Base/Log.h>
#include <Render/Texture.h>

Texture::Texture():
	_frames(1), _ids(0)
{
}

Texture::~Texture() {
	teardown();
}

void Texture::setup(const unsigned int frames) {
	_frames = frames;

	_ids = new GLuint[_frames];
	glGenTextures(_frames, _ids);

	for(unsigned int i=0; i<_frames; i++) {
		enable(i);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		disable();
	}
}

void Texture::teardown() {
	if(_ids) {
		glDeleteTextures(_frames, _ids);
		delete [] _ids;
	}
}

void Texture::setPixelData(SDL_Surface *surface, const unsigned int frame) {
    ASSERT(SDL_LockSurface(surface)==0);
    GLenum format;
    switch(surface->format->BytesPerPixel) {
        case 3: format = GL_RGB; break;
        case 4: format = GL_RGBA; break;
        default: ASSERT(0); break;
    };

    enable(frame);
	gluBuild2DMipmaps(GL_TEXTURE_2D, surface->format->BytesPerPixel, surface->w, surface->h, format, GL_UNSIGNED_BYTE, surface->pixels);
    //glTexImage2D(GL_TEXTURE_2D, 0, format, surface->w, surface->h, 0, format, GL_UNSIGNED_BYTE, surface->pixels);
    disable();
    
    SDL_UnlockSurface(surface);
}

void Texture::enable(const unsigned int frame) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _ids[frame]);
}

void Texture::disable() {
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
}