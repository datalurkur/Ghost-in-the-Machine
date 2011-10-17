#include <GitM/Wall.h>
#include <Engine/PhysicsEngine.h>
#include <Resource/MaterialManager.h>

const std::string Wall::NodeType = "Wall";

Wall::Wall(const std::string &name): Entity(name) {}
Wall::~Wall() {}

void Wall::addVert(const Vector2 &vert) {
    _verts.push_back(vert);
}

void Wall::createRenderables() {
    addRenderable(Renderable::Lines(_verts));
}

void Wall::setupPhysics(PhysicsEngine *physics) {
    _physicsController = addController<PhysicsController,PhysicsEngine>(physics);
    _physicsController->disallowUpdates();
    createPhysicsBody();
}

void Wall::createPhysicsBody() {
    PhysicsEngine *engine = _physicsController->getEngine();
    _physicsController->setBody(engine->createStaticChain(_verts));
}
