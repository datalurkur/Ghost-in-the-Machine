#ifndef PHYSICSCONTROLLER_H
#define PHYSICSCONTROLLER_H

#include <Box2D/Box2D.h>
#include <Engine/Controller.h>

class PhysicsController: public Controller {
public:
    PhysicsController(SceneNode *node, b2Body *body);
    ~PhysicsController();

    void update(int elapsed);

private:
    b2Body *_body;
};

#endif