#ifndef STATE_H
#define STATE_H

class ParentState;

class State {
public:
    State();
    virtual ~State();

    virtual void update(int elapsed) = 0;
    virtual void render() = 0;

protected:
    virtual void setup() = 0;
    virtual void teardown() = 0;

protected:
	friend class ParentState;
    ParentState *_parent;
};

#endif
