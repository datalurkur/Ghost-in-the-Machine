#include <Engine/EventHandler.h>

EventHandler::EventHandler() {
}

void EventHandler::handleEvents() {
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_VIDEORESIZE: {
				WindowListenerList::iterator itr = _windowListeners.begin();
				for(; itr != _windowListeners.end(); itr++) {
					(*itr)->resizeWindow(event.resize.w, event.resize.h);
				}
			} break;
			case SDL_QUIT: {
				WindowListenerList::iterator itr = _windowListeners.begin();
				for(; itr != _windowListeners.end(); itr++) {
					(*itr)->closeWindow();
				}
			} break;
		}
	}
}

void EventHandler::addWindowListener(WindowListener *listener) {
	_windowListeners.push_back(listener);
}