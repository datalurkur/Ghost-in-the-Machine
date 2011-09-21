#include <Engine/Core.h>

Core::Core() {}
Core::~Core() {
    finish();
}

void Core::pushState(State *state) {
    state->setup();
    _stateStack.push(state);
}

State* Core::popState() {
    State *topState = _stateStack.top();

    if(topState) {
        _stateStack.pop();
        topState->teardown();

        return topState;
    } else {
        return NULL;
    }
}

State* Core::activeState() {
    if(_stateStack.empty()) {
        return NULL;
    } else {
        return _stateStack.top();
    }
}

void Core::update(int elapsed) { activeState()->update(elapsed); }
void Core::render()            { activeState()->render();        }

void Core::finish() {
    State *last;
    while((last = popState())) {
        delete last;
    }
}
