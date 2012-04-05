#ifndef GHOSTCORE_H
#define GHOSTCORE_H

#include <Engine/Core.h>

class GhostCore: public Core {
public:
    GhostCore();
    virtual ~GhostCore();
    
    bool keyDown(KeyboardEvent *event);
    
    void setup();
    void teardown();

    bool update(int elapsed);

private:
    enum {
        Starting = 0,
        Established,
        Running
    };

private:
    int _state;
};

#endif
