#ifndef STARTINGSTATE_H
#define STARTINGSTATE_H

#include <Engine/State.h>

class StartingState: public State {
public:
    StartingState();
    virtual ~StartingState();

    bool update(int elapsed);
    bool render(RenderContext *renderContext);

protected:
    void setup(va_list args);
    void teardown();

    void incrementStage();

private:
    enum Stage {
        Start = 0,
        TextureLoading,
        ShaderLoading,
        MaterialLoading,
		TTFLoading,
        Done
    };
    unsigned int _stage;
    unsigned int _progress, _left;
};

#endif
