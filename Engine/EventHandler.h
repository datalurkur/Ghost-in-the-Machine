#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <Base/Base.h>
#include <Engine/WindowListener.h>

class EventHandler {
public:
	EventHandler();

	void handleEvents();

	void addWindowListener(WindowListener *listener);

private:
	typedef std::list<WindowListener*> WindowListenerList;
	WindowListenerList _windowListeners;
};

#endif