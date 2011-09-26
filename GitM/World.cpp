#include <GitM/World.h>

#include <Render/RenderContext.h>

World::World(): _scene(0) {
}

World::~World() {
}

void World::load(const std::string &id) {
    printf("Loading world %s", id.c_str());
}

void World::unload() {
}

void World::render(RenderContext *context) {
}
