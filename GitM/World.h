#ifndef WORLD_H
#define WORLD_H

#include <Base/Base.h>
#include <GitM/QuadTreeSceneManager.h>

class RenderContext;

class World {
public:
	World();
	virtual ~World();

	// Loads the world data from disk / cache
	void load(const std::string &id);

	// Empties the world of loaded world data
	void unload();

	// Render the world
	void render(RenderContext *context);

private:
	QuadTreeSceneManager *_scene;
};

#endif