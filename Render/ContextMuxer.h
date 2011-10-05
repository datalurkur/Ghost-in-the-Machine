#ifndef CONTEXTMUXER_H
#define CONTEXTMUXER_H

#include <Base/Base.h>
#include <Base/Log.h>

template <typename T>
class ContextMuxer {
public:
    static void Setup();

    static T SpawnAndSwap();
    static void SwapAndDestroy(T t);

    static T HeadContext;
};

template <typename T>
T ContextMuxer<T>::HeadContext;

#if SYS_PLATFORM == PLATFORM_APPLE
typedef CGLContextObj Context;
#endif

#endif
