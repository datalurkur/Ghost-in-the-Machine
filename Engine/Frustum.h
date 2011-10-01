#ifndef FRUSTUM_H
#define FRUSTUM_H

#include <Base/Base.h>
#include <Base/Matrix4.h>

class Frustum {
public:
    Frustum();

	void setProjection(const Matrix4 &matrix);
    const Matrix4 getProjection() const;

	Frustum& operator=(const Frustum &other);

private:
	bool _dirty;
	Matrix4 _projection;
};

std::ostream& operator<<(std::ostream& lhs, const Frustum &rhs);

#endif
