#include <Game/SlugWorld.h>

SlugWorld::SlugWorld(): World() {
    _terrain = new Terrain(Vector2(17,17));
    _scene->addNode(_terrain);
}

SlugWorld::~SlugWorld() {
    // We don't need to delete the terrain, because the scene will delete it for us
}
