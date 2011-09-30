#ifndef RENDERCONTEXT_H
#define RENDERCONTEXT_H

#include <Render/Renderable.h>
#include <Render/Viewport.h>
#include <Base/Matrix4.h>

typedef std::list<Renderable*> RenderableList;

class RenderContext {
public:
    RenderContext();
	RenderContext(const Viewport &viewport);

	void render(const Matrix4 &projection, const Matrix4 &modelView, RenderableList &renderables);
	void clear();

	void setViewport(const Viewport &viewport);
    const Viewport getViewport() const;

private:
    Viewport _viewport;
};

#endif