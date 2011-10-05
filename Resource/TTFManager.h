#ifndef TTFMANAGER_H
#define TTFMANAGER_H

#include <Render/Font.h>
#include <Resource/ThreadedResourceManager.h>

class TTFManager;

class TTFManager: public ThreadedResourceManager<Font, TTFManager> {
protected:
    static int ThreadedLoad(void *data);
    
    friend class ThreadedResourceManager<Font, TTFManager>;
};

#endif
