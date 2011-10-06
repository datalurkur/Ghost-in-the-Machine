#ifndef MATERIALMANAGER_H
#define MATERIALMANAGER_H

#include <Render/Material.h>
#include <Resource/ThreadedResourceManager.h>

class MaterialManager;

class MaterialManager: public ThreadedResourceManager<Material, MaterialManager> {
protected:
    static void DoLoad(const std::string &name, Material *material);
    
    friend class ThreadedResourceManager<Material, MaterialManager>;
};

#endif