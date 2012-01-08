#ifndef SIMPLECORE_H
#define SIMPLECORE_H

#include <Engine/Core.h>

class SimpleCore: public Core {
public:
    SimpleCore();
    virtual ~SimpleCore();
    
    void keyDown(KeyboardEvent *event);
    
    void setup();
    void teardown();
};

#endif
