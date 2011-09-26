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

bool ParentState::popState(bool deleteOnPop = true) {
    State *state = _stateStack.top();

    if(state) {
        _stateStack.pop();
        state->teardown();
		if(deleteOnPop) {
			delete state;
		}
        return true;
    } else {
        return false;
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
    while(popState()) {}
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
