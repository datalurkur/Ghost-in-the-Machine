#include <GitM/World.h>

#include <Base/Log.h>
#include <Render/RenderContext.h>

// FIXME - The ratio for the orthographic projection needs to come from elsewhere, this is not the place for it.
World::World(): _player(0), _projection(Matrix4::MakeOrtho(-(640.0/480.0), (640.0/480.0), -1.0, 1.0, -1.0, 1.0)), _modelView(Matrix4::Identity) {
	_scene = new QuadTreeSceneManager();
}

World::~World() {
	delete _scene;
    if(_player) {
        delete _player;
    }
}

void World::render(Camera *camera, RenderContext *context) {
	RenderableList renderables;
	context->render(camera->getProjectionMatrix(), _modelView, renderables);
}

SceneManager* World::getScene() {
	return _scene;
}
