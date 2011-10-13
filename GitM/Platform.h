#ifndef PLATFORM_H
#define PLATFORM_H

#include <Engine/Entity.h>

class Platform: public Entity {
public:
    static const std::string NodeType;

public:
    Platform(const std::string &name);
    Platform(const std::string &name, va_list args);
    virtual ~Platform();
    
    void recreateRenderables();
    
    void setupPhysics(PhysicsEngine *physics);
    void recreatePhysicsBody();

private:
};

#endif