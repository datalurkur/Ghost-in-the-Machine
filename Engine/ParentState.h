#ifndef PARENTSTATE_H
#define PARENTSTATE_H

#include <Engine/State.h>
#include <stack>

class ParentState: public State {
public:
    ParentState();
    virtual ~ParentState();

    void setState(State *state, va_list args);
    void pushState(State *state, va_list args);
    State *popState();
    State *activeState();

    void flushStates();

    virtual void update(int elapsed);
    virtual void render();

protected:
	virtual void setup(va_list args) {}
	virtual void teardown() {}

private:
    std::stack <State*> _stateStack;
};

#endif
