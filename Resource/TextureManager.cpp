#include <Resource/TextureManager.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_image.h>

void TextureManager::DoLoad(const std::string &name, Texture *texture) {
	// Create an SDL surface with the image data
	SDL_Surface *tSurf;
	tSurf = IMG_Load(name.c_str());

    // Setup the texture
    texture->setup();
    texture->setPixelData(tSurf);

	// Destroy the SDL surface
	SDL_FreeSurface(tSurf);
}
