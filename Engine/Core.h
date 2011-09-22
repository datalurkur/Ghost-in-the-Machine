#ifndef CORE_H
#define CORE_H

#include <Engine/ParentState.h>

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
