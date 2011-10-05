#include <Resource/TextureManager.h>
#include <Render/ContextMuxer.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_image.h>

int TextureManager::ThreadedLoad(void *data) {
    ResourceThreadParams *params = (ResourceThreadParams*)data;
    Texture *texture = (Texture*)params->ptr;
	std::string name = params->name;

	// Create an SDL surface with the image data
	SDL_Surface *tSurf;
	tSurf = IMG_Load(name.c_str());

    Context oldContext = ContextMuxer<Context>::SpawnAndSwap();

    // Setup the texture
    texture->setup();
    texture->setPixelData(tSurf);

    ContextMuxer<Context>::SwapAndDestroy(oldContext);

	Finish(texture);

    return 1;
}
