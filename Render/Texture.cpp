#include <Render/Texture.h>
#include <SDL/SDL_opengl.h>

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

void Texture::enable(const unsigned int frame) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _ids[frame]);
}

void Texture::disable() {
	glBindTexture(GL_TEXTURE_2D, 0);
}