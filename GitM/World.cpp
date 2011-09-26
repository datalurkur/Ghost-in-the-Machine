#include <GitM/World.h>

#include <Base/Log.h>
#include <Render/RenderContext.h>

World::World(): _scene(0) {
}

World::~World() {
}

void World::load(const std::string &map) {
    Info("Loading map " << map);
}

void World::unload() {
}

void World::render(RenderContext *context) {
}
