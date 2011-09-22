#ifndef PARENTSTATE_H
#define PARENTSTATE_H

#include <Engine/State.h>
#include <stack>

class ParentState: public State {
public:
    ParentState();
    ~ParentState();

    void pushState(State *state);
    State *popState();
    State *activeState();

    void flushStates();

    virtual void update(int elapsed);
    virtual void render();

protected:
	virtual void setup() {}
	virtual void teardown() {}

private:
    std::stack <State*> _stateStack;
};

#endif
