#ifndef THREADEDTEXTUREFACTORY_H
#define THREADEDTEXTUREFACTORY_H

#include <Render/Texture.h>
#include <Resource/ThreadedFactory.h>

class ThreadedTextureFactory;

class ThreadedTextureFactory: public ThreadedFactory<Texture, ThreadedTextureFactory> {
protected:
    static int ThreadedLoad(void *data);
    
    friend class ThreadedFactory<Texture, ThreadedTextureFactory>;
};

#endif