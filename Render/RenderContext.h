#ifndef RENDERCONTEXT_H
#define RENDERCONTEXT_H

#include <Render/Renderable.h>

typedef std::list<Renderable*> RenderableList;

class RenderContext {
public:
	RenderContext();
	virtual ~RenderContext();

	// FIXME - render should take modelview and projection matrices
	void render(RenderableList &renderables);
	void clear();

private:
};

#endif