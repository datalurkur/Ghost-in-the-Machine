#include <GitM/World.h>

#include <Base/Log.h>
#include <Render/RenderContext.h>

World::World(): _player(0) {
	_scene = new QuadTreeSceneManager();
}

World::~World() {
	delete _scene;
    if(_player) {
        delete _player;
    }
}

void World::render(RenderContext *context) {
}

SceneManager* World::getScene() {
	return _scene;
}