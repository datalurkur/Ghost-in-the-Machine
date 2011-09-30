#ifndef WORLD_H
#define WORLD_H

#include <Base/Base.h>
#include <Base/Matrix4.h>
#include <GitM/QuadTreeSceneManager.h>
#include <GitM/Player.h>

class RenderContext;
class ThreadedWorldFactory;

class World {
public:
	World();
	virtual ~World();

	// Render the world
	void render(RenderContext *context);

	// Return the scene manager
	SceneManager *getScene();

protected:
	QuadTreeSceneManager *_scene;
	Player *_player;
	Matrix4 _projection, _modelView;

    friend class ThreadedWorldFactory;
};

#endif