#ifndef RENDERQUEUE_H
#define RENDERQUEUE_H

#include <Render/Renderable.h>
#include <list>

class RenderQueue {
public:
	RenderQueue();
	virtual ~RenderQueue();

private:
	std::list<Renderable*> _renderables;
};

#endif
