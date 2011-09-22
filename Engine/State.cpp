#include <Engine/State.h>

State::State(): _parent(0) {
}

State::~State() {
}

void State::setParent(ParentState *parent) {
    //ASSERT(parent == 0 || _parent == 0);
    _parent = parent;
}
