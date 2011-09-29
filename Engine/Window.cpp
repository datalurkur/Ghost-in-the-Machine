#include <Engine/Window.h>
#include <Base/Log.h>

Window::Window(): _w(0), _h(0), _videoFlags(0), _frameBuffer(0) { setup(); }
Window::Window(int w, int h): _w(w), _h(h), _videoFlags(0), _frameBuffer(0) { setup(); }

Window::~Window() {
	if(_frameBuffer) {
		SDL_FreeSurface(_frameBuffer);
	}
	SDL_Quit();
}

void Window::setup() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		// FIXME - Make this an assert
		Error("SDL Failed to initialize");
	}

	_videoFlags |= SDL_GL_DOUBLEBUFFER;
	_videoFlags |= SDL_HWSURFACE;
	_videoFlags |= SDL_OPENGL;

	resize(_w, _h);
}

void Window::resize(int w, int h) {
	_w = w;
	_h = h;

	if(_frameBuffer) {
		SDL_FreeSurface(_frameBuffer);
	}

	if(!(_frameBuffer = SDL_SetVideoMode(_w, _h, 32, _videoFlags))) {
		Error("Failed to create frame buffer.");
	}
}

void Window::swapBuffers() const {
	SDL_GL_SwapBuffers();
}