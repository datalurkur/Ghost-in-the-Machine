#include <GitM/Platform.h>
#include <Engine/PhysicsEngine.h>
#include <Resource/MaterialManager.h>

const std::string Platform::NodeType = "Platform";

Platform::Platform(const std::string &name):
    Entity(name)
{
    recreateRenderables();
}

Platform::Platform(const std::string &name, va_list args):
    Entity(name)
{
    _position = *va_arg(args, Vector2*);
    _dimensions = *va_arg(args, Vector2*);
    recreateRenderables();
}

Platform::~Platform() {}

void Platform::recreateRenderables() {
    addRenderable(Renderable::Sprite(_position.x, _position.y, _dimensions.x, _dimensions.y, 0, MaterialManager::Get("playerMaterial")));
}

void Platform::setupPhysics(PhysicsEngine *physics) {
    addController(physics);
    _pController->disallowUpdates();
    recreatePhysicsBody();
}

void Platform::recreatePhysicsBody() {
    PhysicsEngine *engine = _pController->getEngine();
    _pController->setBody(engine->createStaticBox(_position, _dimensions));
}