#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <Render/Texture.h>
#include <Resource/ThreadedResourceManager.h>

class TextureManager;

class TextureManager: public ResourceManager<Texture, TextureManager> {
protected:
    static void DoLoad(const std::string &name, Texture *texture);

    friend class ResourceManager<Texture, TextureManager>;
};

#endif
