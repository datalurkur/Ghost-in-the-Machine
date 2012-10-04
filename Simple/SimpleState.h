#ifndef SIMPLESTATE_H
#define SIMPLESTATE_H

#include <Engine/State.h>

class SimpleWorld;

class SimpleState: public State {
public:
    SimpleState();
    virtual ~SimpleState();

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
		WorldSetup,
		Running
    };
    unsigned int _stage;
    unsigned int _progress, _left;
	SimpleWorld *_world;
};

#endif
