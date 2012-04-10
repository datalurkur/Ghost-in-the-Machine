#include <Game/Platform.h>
#include <Engine/PhysicsEngine.h>
#include <Resource/MaterialManager.h>

const std::string Platform::NodeType = "Platform";

Platform::Platform(const std::string &name):
    Entity(name)
{
    recreateRenderables();
}

Platform::~Platform() {}

void Platform::recreateRenderables() {
    addRenderable(Renderable::Sprite(Vector2(_position.x, _position.y), Vector2(_dimensions.x, _dimensions.y), 0, MaterialManager::Get("platform")));
}

void Platform::setupPhysics(PhysicsEngine *physics) {
    _physicsController = addController<PhysicsController,PhysicsEngine>(physics);
    _physicsController->disallowUpdates();
    createPhysicsBody();
}

void Platform::createPhysicsBody() {
    PhysicsEngine *engine = _physicsController->getEngine();
    _physicsController->setBody(engine->createStaticBox(Vector2(_position.x, _position.y), Vector2(_dimensions.x, _dimensions.y)));
}