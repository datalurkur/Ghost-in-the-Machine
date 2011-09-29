#ifndef THREADEDFACTORY_H
#define THREADEDFACTORY_H

#include <Base/Base.h>
#include <Base/Log.h>

#include "SDL_mutex.h"
#include "SDL_thread.h"

#define LOCK_MUTEX \
    do { \
        ASSERT(Lock); \
        SDL_mutexP(Lock); \
    } while(false)

#define UNLOCK_MUTEX \
    do { \
        SDL_mutexV(Lock); \
    } while(false)

struct ThreadInfo {
    SDL_Thread *thread;
    float progress;
    std::string status;
    
    ThreadInfo();
    ThreadInfo(SDL_Thread *nThread);
};

template <typename T, typename F>
class ThreadedFactory {
public:
    static void Setup();
    static void Teardown();

    static T* Load(const std::string &name);
    static void Finish(T* t);

    static float Progress(T* t);
    static std::string Status(T* t);
    static bool IsDone(T* t);

    typedef std::map<T*,ThreadInfo> ThreadMap;
    typedef typename ThreadMap::iterator ThreadMapIterator;
    
protected:
    static int ThreadedLoad(void* data);

    static void UpdateProgress(T* t, float progress);
    static void UpdateStatus(T* t, const std::string &status);
    
    static ThreadInfo* GetThreadInfo(T* t);

protected:
    static SDL_mutex* Lock;
    static ThreadMap Threads;
};

template <typename T, typename F>
SDL_mutex* ThreadedFactory<T,F>::Lock = SDL_CreateMutex();

template <typename T, typename F>
typename ThreadedFactory<T,F>::ThreadMap ThreadedFactory<T,F>::Threads;

template <typename T, typename F>
void ThreadedFactory<T,F>::Setup() {
    Lock = SDL_CreateMutex();
}

template <typename T, typename F>
void ThreadedFactory<T,F>::Teardown() {
    if(Lock) {
        SDL_mutexP(Lock);
        ThreadMapIterator itr = Threads.begin();
        for(; itr != Threads.end(); itr++) {
            SDL_KillThread(itr->second.thread);
        }
        Threads.clear();
        SDL_DestroyMutex(Lock);
        Lock = 0;
    }
}

template <typename T, typename F>
T* ThreadedFactory<T,F>::Load(const std::string &name) {
    T* t = new T();

    LOCK_MUTEX;
    Threads[t] = ThreadInfo(SDL_CreateThread(F::ThreadedLoad, t));
    UNLOCK_MUTEX;

    return t;
}

template <typename T, typename F>
void ThreadedFactory<T,F>::Finish(T *t) {
    LOCK_MUTEX;
    Threads.erase(t);
    UNLOCK_MUTEX;
}

template <typename T, typename F>
float ThreadedFactory<T,F>::Progress(T *t) {
    float progress;
    ThreadInfo* threadInfo;

    LOCK_MUTEX;
    if((threadInfo = GetThreadInfo(t))) {
        progress = threadInfo->progress;
    }
    UNLOCK_MUTEX;
    
    return progress;
}

template <typename T, typename F>
std::string ThreadedFactory<T,F>::Status(T *t) {
    std::string status;
    ThreadInfo* threadInfo; 

    LOCK_MUTEX;
    if((threadInfo = GetThreadInfo(t))) {
        status = threadInfo->status;
    }
    UNLOCK_MUTEX;
    
    return status;
}

template <typename T, typename F>
bool ThreadedFactory<T,F>::IsDone(T *t) {
    bool done;

    LOCK_MUTEX;
    done = !GetThreadInfo(t);
    UNLOCK_MUTEX;
    
    return done;
}

template <typename T, typename F>
int ThreadedFactory<T,F>::ThreadedLoad(void* data) {
    Error("ThreadedLoad not implemented for default ThreadedFactory");
    Finish((T*)data);
    return 0;
}

template <typename T, typename F>
void ThreadedFactory<T,F>::UpdateProgress(T* t, float progress) {
    LOCK_MUTEX;
    Threads[t].progress = progress;
    UNLOCK_MUTEX;
}

template <typename T, typename F>
void ThreadedFactory<T,F>::UpdateStatus(T* t, const std::string &status) {
    LOCK_MUTEX;
    Threads[t].status = status;
    UNLOCK_MUTEX;
}

// WARNING: This function is not threadsafe, and is designed to be called
//  from within functions that make use of mutex locking
template <typename T, typename F>
ThreadInfo* ThreadedFactory<T,F>::GetThreadInfo(T *t) {
    ThreadMapIterator itr = Threads.find(t);
    if(itr != Threads.end()) {
        return &(itr->second);
    } else {
        return 0;
    }
}

#undef LOCK_MUTEX
#undef UNLOCK_MUTEX

#endif
