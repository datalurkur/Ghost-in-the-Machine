#ifndef RENDERCONTEXT_H
#define RENDERCONTEXT_H

#include <Render/Renderable.h>
#include <Base/Matrix4.h>

typedef std::list<Renderable*> RenderableList;

class RenderContext {
public:
	RenderContext();
	virtual ~RenderContext();

	void render(const Matrix4 &projection, const Matrix4 &modelView, RenderableList &renderables);
	void clear();

	void setViewport(int x, int y, int w, int h);
private:
};

#endif