#ifndef GHOSTCORE_H
#define GHOSTCORE_H

#include <Engine/Core.h>

class GhostCore: public Core {
public:
    GhostCore();
    virtual ~GhostCore();
    
    void keyDown(KeyboardEvent *event);
    
    void setup();
    void teardown();
};

#endif
