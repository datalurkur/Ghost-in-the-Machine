#ifndef FRUSTUM_H
#define FRUSTUM_H

class Matrix4;

class Frustum {
public:
    Frustum();

    void setAspectRatio(const float ratio);
    const float getAspectRatio() const;
    
    const Matrix4 getProjectionMatrix() const;

private:
    float _aspectRatio;
};

#endif
