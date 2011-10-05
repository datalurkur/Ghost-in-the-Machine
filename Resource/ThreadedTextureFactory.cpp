#include <Resource/ThreadedTextureFactory.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_opengl.h>

int ThreadedTextureFactory::ThreadedLoad(void *data) {
    Texture *texture = ((FactoryThreadParams<Texture>*)data)->ptr;
	std::string name = ((FactoryThreadParams<Texture>*)data)->name;

    // FIXME - SDL 1.2 doesn't support rendering context creation
    //  Upon release of SDL 1.3, it will make sense to revisit this and create
    //   a separate context for non-blocking texture loading

	// Load the texture
	SDL_Surface *tSurf;
	//tSurf = IMG_Load(name.c_str());
	// FIXME - Finish image loading
	
	Finish(texture);

    return 1;
}