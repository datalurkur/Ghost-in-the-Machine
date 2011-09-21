#ifndef STATE_H
#define STATE_H

class Core;

class State {
public:
    State();
    virtual ~State();

    virtual void setup() = 0;
    virtual void teardown() = 0;

    virtual void update(int elapsed) = 0;
    virtual void render() = 0;

private:
    Core *_parent;
};

#endif
