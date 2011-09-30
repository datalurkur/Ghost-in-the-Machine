#include <Render/RenderContext.h>

#include "SDL_opengl.h"

RenderContext::RenderContext() {
}

RenderContext::~RenderContext() {
}

void RenderContext::render(const Matrix4 &projection, const Matrix4 &modelView, RenderableList &renderables) {
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(projection.ptr());

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(modelView.ptr());
	// FIXME - Remove static loading and implement renderable list rendering
	// FIXME - Add the render queue and group rendering by material

	float vert_val = 0.5;
	float verts[24] = {
		-vert_val, -vert_val, 0.0,
		 vert_val, -vert_val, 0.0,
		 vert_val,  vert_val, 0.0,
		-vert_val,  vert_val, 0.0,
		 
		 vert_val*2, -vert_val, 0.0,
		 vert_val*3, -vert_val, 0.0,
		 vert_val*3, vert_val, 0.0,
		 vert_val*2, vert_val, 0.0
	};
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
		for(int i=0; i<8; i++) {
			glVertex3fv(&(verts[i*3]));
		}
	glEnd();
}

void RenderContext::clear() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderContext::setViewport(int x, int y, int w, int h) {
	glViewport(x, y, w, h);
}