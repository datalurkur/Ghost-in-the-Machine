#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <Render/Texture.h>
#include <Resource/ThreadedResourceManager.h>

class TextureManager;

class TextureManager: public ThreadedResourceManager<Texture, TextureManager> {
protected:
    static int ThreadedLoad(void *data);
    
    friend class ThreadedResourceManager<Texture, TextureManager>;
};

#endif
