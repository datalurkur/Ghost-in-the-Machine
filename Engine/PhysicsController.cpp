#include <Engine/PhysicsController.h>

PhysicsController::PhysicsController(SceneNode *node, b2Body *body):
    Controller(node), _body(body)
{}

PhysicsController::~PhysicsController() {}

void PhysicsController::update(int elapsed) {
    b2Vec2 pos = _body->GetPosition();
    _node->setPosition(pos.x, pos.y);
}