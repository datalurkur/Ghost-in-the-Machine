#include <Engine/State.h>

State::State(): _parent(NULL) {
}

State::~State() {
}

void State::setParent(ParentState *parent) {
    ASSERT(parent == NULL || _parent == NULL);
    _parent = parent;
}
