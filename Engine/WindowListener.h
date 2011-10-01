#ifndef WINDOWLISTENER_H
#define WINDOWLISTENER_H

#include <Engine/EventListener.h>

class WindowListener: public EventListener {
public:
	WindowListener();

	virtual void resizeWindow(const int w, const int h) = 0;
	virtual void closeWindow() = 0;
};

#endif