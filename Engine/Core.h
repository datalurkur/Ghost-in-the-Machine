#ifndef CORE_H
#define CORE_H

#include <Engine/State.h>
#include <stack>

class Core {
public:
    Core();
    ~Core();

    void pushState(State *state);
    State *popState();
    State *activeState();

    void update(int elapsed);
    void render();

    void finish();

private:
    std::stack <State*> _stateStack;
};

#endif
