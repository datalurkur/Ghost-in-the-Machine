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

void World::update(int elapsed) {
    EntityList::iterator itr = _entities.begin();
    for(; itr != _entities.end(); itr++) {
        itr->second->update(elapsed);
    }
}

void World::render(Camera *camera, RenderContext *context) {
	_scene->render(camera, context);
}

SceneManager* World::getScene() {
	return _scene;
}
