#ifndef THREADEDTTFFACTORY_H
#define THREADEDTTFFACTORY_H

#include <Render/Font.h>
#include <Resource/ThreadedFactory.h>

class ThreadedTTFFactory;

class ThreadedTTFFactory: public ThreadedFactory<Font, ThreadedTTFFactory> {
protected:
    static int ThreadedLoad(void *data);
    
    friend class ThreadedFactory<Font, ThreadedTTFFactory>;
};

#endif