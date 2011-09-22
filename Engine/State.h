#ifndef STATE_H
#define STATE_H

#include <stdarg.h>

class ParentState;

class State {
public:
    State();
    virtual ~State();

    virtual void update(int elapsed) = 0;
    virtual void render() = 0;

protected:
    virtual void setup(va_list args) = 0;
    virtual void teardown() = 0;

    void setParent(ParentState *parent);

protected:
	friend class ParentState;
    ParentState *_parent;
};

#endif
