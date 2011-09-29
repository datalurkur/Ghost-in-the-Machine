#ifndef RENDERCONTEXT_H
#define RENDERCONTEXT_H

#include <Render/Renderable.h>

typedef std::list<Renderable*> RenderableList;

class RenderContext {
public:
	RenderContext();
	virtual ~RenderContext();

	void render(RenderableList &renderables);

private:
};

#endif