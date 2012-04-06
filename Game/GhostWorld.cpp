#include <Game/GhostWorld.h>
#include <Game/Platform.h>
#include <Game/Wall.h>

GhostWorld::GhostWorld(): World(), _player(0) {
}

GhostWorld::~GhostWorld() {
	// Deleting the player object is unnecessary (undesirable, even), since the scene manager deletes it for us
}

void GhostWorld::load(const std::string &name) {
    _player = Player::DefaultPlayer(); //new Player("herpus");
    _player->setPosition(0.5f, 2.0f, 0.0f);
    addEntity(_player);

    Platform *platform = new Platform("platform01");
    platform->setPosition(0.0f, -2.0f, 0.0f);
    platform->setDimensions(5.0f, 1.0f, 0.0f);
    addEntity(platform);
/*
    platform = new Platform("platform02");
    platform->setPosition(-4.5, 2.5, 0.0);
    platform->setDimensions(1, 5);
    addEntity(platform);

    platform = new Platform("platform03");
    platform->setPosition(4.5, 2.5);
    platform->setDimensions(1, 5);
    addEntity(platform);

    Wall *wallSegment = new Wall("wall01");
    Vector2 verts[6] = {
        Vector2(10.0f, -5.0f),
        Vector2(5.0f, -7.0f),
        Vector2(-5.0f, -7.0f),
        Vector2(-10.0f, -5.0f),
		Vector2(-10.0f, 0.0f),
		Vector2(-5.0f, 5.0f)
    };

    wallSegment->setVerts(verts, 6);
    wallSegment->recreateRenderables();
    addEntity(wallSegment);*/
}

Player* GhostWorld::getPlayer() {
    return _player;
}
