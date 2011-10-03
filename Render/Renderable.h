#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <Base/Base.h>
#include <Base/Matrix4.h>

class Renderable {
public:
	Renderable();
	virtual ~Renderable();

	void setViewMatrix(const Matrix4 &matrix);
	const Matrix4& getViewMatrix() const;

private:
	Matrix4 _viewMatrix;
};

typedef std::list<Renderable*> RenderableList;

#endif
