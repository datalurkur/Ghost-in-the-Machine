#include <GitM/World.h>

#include <Base/Log.h>
#include <Render/RenderContext.h>

World::World() {
	_scene = new QuadTreeSceneManager();
}

World::~World() {
	delete _scene;
}

void World::load(const std::string &map) {
    Info("Loading map " << map);

	_player = new Player("derpus");
	_scene->addNode(_player);
}

void World::unload() {
	_scene->deleteNode<Player>(_player->getName());
}

void World::render(RenderContext *context) {
}

SceneManager* World::getScene() {
	return _scene;
}