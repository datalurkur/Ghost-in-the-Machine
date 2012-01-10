#include <Game/World.h>

#include <Base/Log.h>
#include <Engine/Entity.h>
#include <Render/RenderContext.h>

World::World() {
	_scene = new QuadTreeSceneManager();
    _physics = new PhysicsEngine();
	_terrain = new Terrain(Vector2(9,9));

	_scene->addNode(_terrain);
}

World::~World() {
	// We don't need to delete the terrain, because the scene will delete it for us
	delete _scene;

	delete _physics;
}

void World::update(int elapsed) {
    EntityList::iterator itr;
    
	// Tick the physics simulation
    _physics->update(elapsed);

    // Update the entities (and their controllers)
    for(itr = _entities.begin(); itr != _entities.end(); itr++) {
        itr->second->update(elapsed);
    }

    // Update the scene
    _scene->update();
}

void World::render(Camera *camera, RenderContext *context) {
	_scene->render(camera, context);
}

SceneManager* World::getScene() {
	return _scene;
}