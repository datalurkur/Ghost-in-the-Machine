#ifndef PARENTSTATE_H
#define PARENTSTATE_H

#include <Engine/State.h>

class ParentState: public State {
public:
    ParentState();
    ~ParentState();

    void pushState(State *state);
    State *popState();
    State *activeState();

    void flushStates();

private:
    std::stack <State*> _stateStack;
};

#endif
