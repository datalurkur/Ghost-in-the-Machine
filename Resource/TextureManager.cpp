#include <Resource/TextureManager.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_image.h>

int TextureManager::ThreadedLoad(void *data) {
    Texture *texture = ((ResourceThreadParams<Texture>*)data)->ptr;
	std::string name = ((ResourceThreadParams<Texture>*)data)->name;

    // FIXME - SDL 1.2 doesn't support rendering context creation
    //  Upon release of SDL 1.3, it will make sense to revisit this and create
    //   a separate context for non-blocking texture loading

	// Create an SDL surface with the image data
	SDL_Surface *tSurf;
	tSurf = IMG_Load(name.c_str());
	
	Finish(texture);

    return 1;
}
