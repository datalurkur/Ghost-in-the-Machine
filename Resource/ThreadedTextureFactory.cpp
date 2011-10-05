#include <Resource/ThreadedTextureFactory.h>
#include <Render/RenderContext.h>
#include <SDL/SDL_image.h>

int ThreadedTextureFactory::ThreadedLoad(void *data) {
    Texture *texture = ((FactoryThreadParams<Texture>*)data)->ptr;
	std::string name = ((FactoryThreadParams<Texture>*)data)->name;

	// Create a temporary rendering context so that we don't block the main rendering context from rendering while loading textures
	HDC hdc;
	HGLRC context;

	// Get the current device context, use it to create a new render context, and make the new context current
	hdc = wglGetCurrentDC();
	context = wglCreateContext(hdc);
	wglMakeCurrent(hdc, context);

	// Load the texture
	SDL_Surface *tSurf;
	//tSurf = IMG_Load(name.c_str());
	// FIXME - Finish image loading

	// Done with our temporary render context, kill it
	wglMakeCurrent(0, 0);
	wglDeleteContext(context);
	
	Finish(texture);

    return 1;
}