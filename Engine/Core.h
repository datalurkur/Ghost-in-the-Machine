#ifndef CORE_H
#define CORE_H

#include <Engine/State.h>
#include <stack>

class Core: public ParentState {
public:
    Core();
    ~Core();

    void start();
    void stop();

protected:
    int getTime();

private:
    bool _running;
};

#endif
