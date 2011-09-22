#include <Engine/ParentState.h>

ParentState::ParentState() {
}

ParentState::~ParentState() {
}

void ParentState::pushState(State *state) {
    state->setup();
    _stateStack.push(state);
}

State* ParentState::popState() {
    State *state = _stateStack.top();

    if(state) {
        _stateStack.pop();
        state->teardown();

        return state;
    } else {
        return NULL;
    }
}

State* ParentState::activeState() {
    if(_stateStack.empty()) {
        return NULL;
    } else {
        return _stateStack.top();
    }
}

void ParentState::update(int elapsed) { activeState()->update(elapsed); }
void ParentState::render()            { activeState()->render();        }

void ParentState::flushStates() {
    State *last;
    while((last = popState())) {}
}
