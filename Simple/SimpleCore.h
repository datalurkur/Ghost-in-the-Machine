#ifndef SIMPLECORE_H
#define SIMPLECORE_H

#include <Engine/Core.h>

class SimpleCore: public Core {
public:
    SimpleCore();
    virtual ~SimpleCore();
    
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
