#include <Resource/TextureManager.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_image.h>

const std::string TextureManager::LoadDirectory = "Texture";

void TextureManager::DoLoad(const std::string &name, Texture *texture) {
	std::string fullName = LoadPath() + name;

	// Create an SDL surface with the image data
	SDL_Surface *tSurf;
	tSurf = IMG_Load(fullName.c_str());

    // Setup the texture
    texture->setup();
    texture->setPixelData(tSurf);

	// Destroy the SDL surface
	SDL_FreeSurface(tSurf);
}
