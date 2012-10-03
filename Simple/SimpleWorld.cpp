#include <Simple/SimpleWorld.h>
#include <Game/Platform.h>
#include <Game/Wall.h>

SimpleWorld::GhostWorld(): World() {
}

SimpleWorld::~GhostWorld() {
}

void SimpleWorld::update(int elapsed) {
	World::update(elapsed);
}