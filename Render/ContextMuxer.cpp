#include <Render/ContextMuxer.h>

#if SYS_PLATFORM == PLATFORM_APPLE
template <>
void ContextMuxer<Context>::Setup() {
    Info("Setting up context muxer");
    HeadContext = CGLGetCurrentContext();
    Info(" - HEAD set to " << HeadContext);
}

template <>
Context ContextMuxer<Context>::SpawnAndSwap() {
    Context oldContext, newContext;
    Info("Spawning and swapping");
    
    oldContext = CGLGetCurrentContext();
    Info(" - OLD " << oldContext);
    
    CGLPixelFormatObj pFormat = CGLGetPixelFormat(HeadContext);
    CGLCreateContext(pFormat, HeadContext, &newContext);
    Info(" - NEW " << newContext);
    
    CGLSetCurrentContext(newContext);
    
    return oldContext;
}

template <>
void ContextMuxer<Context>::SwapAndDestroy(Context context) {
    Context current = CGLGetCurrentContext();
    if(context) {
        Info("Resetting to context ");
        CGLSetCurrentContext(context);
    } else {
        Info("Resetting to HEAD");
        CGLSetCurrentContext(HeadContext);
    }
    CGLDestroyContext(current);
}
#endif