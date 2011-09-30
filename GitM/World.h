#ifndef WORLD_H
#define WORLD_H

#include <Base/Base.h>
#include <Base/Matrix4.h>
#include <GitM/QuadTreeSceneManager.h>
#include <GitM/Player.h>

class Camera;
class RenderContext;
class ThreadedWorldFactory;

class World {
public:
	World();
	virtual ~World();

	// Render the world
	void render(Camera *camera, RenderContext *context);

	// Return the scene manager
	SceneManager *getScene();
    
    template <typename T>
    T *create(const std::string &name);

protected:
	QuadTreeSceneManager *_scene;
	Player *_player;
	Matrix4 _projection, _modelView;

    friend class ThreadedWorldFactory;
};

template <typename T>
T* World::create(const std::string &name) {
    T *newObject = new T(name);
    _scene->addNode(newObject);
    return newObject;
}

#endif