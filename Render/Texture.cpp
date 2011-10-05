#include <Base/Base.h>
#include <Render/Texture.h>

Texture::Texture():
	_frames(1), _ids(0)
{
}

Texture::~Texture() {
	if(_ids) {
		glDeleteTextures(_frames, _ids);
		delete [] _ids;
	}
}

void Texture::setup(const unsigned int frames) {
	_frames = frames;

	_ids = new GLuint[_frames];
	glGenTextures(_frames, _ids);
}

void Texture::setPixelData(SDL_Surface *surface, const unsigned int frame) {
    ASSERT(SDL_LockSurface(surface)==0);
    GLenum format;
    
    switch(surface->format->BytesPerPixel) {
        case 3: format = GL_BGR; break;
        case 4: format = GL_BGRA; break;
        default: ASSERT(0); break;
    };

    // NOTE: For now, we are using the same internal format as the format of the data
    enable(frame);
    glTexImage2D(GL_TEXTURE_2D, 0, format, surface->w, surface->h, 0, format, GL_UNSIGNED_BYTE, surface->pixels);
    disable();
    
    SDL_UnlockSurface(surface);
}

void Texture::enable(const unsigned int frame) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _ids[frame]);
}

void Texture::disable() {
	glBindTexture(GL_TEXTURE_2D, 0);
}