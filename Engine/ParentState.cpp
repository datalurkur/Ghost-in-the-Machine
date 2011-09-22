#include <Engine/ParentState.h>

ParentState::ParentState() {
}

ParentState::~ParentState() {
}

void ParentState::setState(State *state, ...) {
    va_list args;
    va_start(args, state);
    setState(state, args);
    va_end(args);
}

void ParentState::setState(State *state, va_list args) {
    flushStates();
    pushState(state, args);
}

void ParentState::pushState(State *state, ...) {
    va_list args;
    va_start(args, state);
    pushState(state, args);
    va_end(args);
}

void ParentState::pushState(State *state, va_list args) {
    state->setParent(this);
    state->setup(args);
    _stateStack.push(state);
}

State* ParentState::popState() {
    State *state = _stateStack.top();

    if(state) {
        _stateStack.pop();
        state->teardown();
        state->setParent(NULL);

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

void ParentState::flushStates() {
    State *last;
    while((last = popState())) {}
}

void ParentState::update(int elapsed) {
    if(activeState()) {
        activeState()->update(elapsed);
    }
}

void ParentState::render() {
    if(activeState()) {
        activeState()->render();
    }
}
