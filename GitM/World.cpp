#include <GitM/World.h>

#include <Base/Log.h>
#include <Render/RenderContext.h>

World::World(): _player(0) {
	_scene = new QuadTreeSceneManager();
    _physicsSystem = new PhysicsSystem();
}

World::~World() {
    delete _physicsSystem;
	delete _scene;
}

void World::update(int elapsed) {
    EntityList::iterator itr = _entities.begin();
    for(; itr != _entities.end(); itr++) {
        itr->second->update(elapsed);
    }
    _scene->update();
}

void World::render(Camera *camera, RenderContext *context) {
	_scene->render(camera, context);
}

SceneManager* World::getScene() {
	return _scene;
}

Player* World::getPlayer() {
    return _player;
}