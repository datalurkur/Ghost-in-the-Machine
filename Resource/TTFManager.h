#ifndef TTFMANAGER_H
#define TTFMANAGER_H

#include <Render/Font.h>
#include <Resource/ThreadedResourceManager.h>

class TTFManager;

class TTFManager: public ThreadedResourceManager<Font, TTFManager> {
protected:
    static void DoLoad(const std::string &name, Font *font);
    
    friend class ThreadedResourceManager<Font, TTFManager>;
};

#endif
