#ifndef ISOCAMERA_H
#define ISOCAMERA_H

#include <Engine/Camera.h>

#define STANDARD_FOV 3.14159f / 4.0f // 45 degrees

class IsoCamera: public Camera {
public:
	IsoCamera(const std::string &name);
	virtual ~IsoCamera();

	void setAspectRatio(const float ratio);

private:
	float _fov, _near, _far;
};

#endif