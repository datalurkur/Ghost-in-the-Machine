#ifndef THREADEDFACTORY_H
#define THREADEDFACTORY_H

#include <Base/Base.h>
#include <Base/Log.h>

#include "SDL_mutex.h"
#include "SDL_thread.h"

struct ThreadInfo {
    SDL_Thread *thread;
    float progress;
    std::string status;
    bool done;
    
    ThreadInfo();
    ThreadInfo(SDL_Thread *nThread);
};

template <typename T>
class ThreadedFactory {
public:
    static T *Load(const std::string &name);
    static void Finish(T *t);

    static float Progress(T *t);
    static std::string Status(T *t);
    static bool IsDone(T *t);
    
protected:
    static int ThreadedLoad(void *data);

    static void UpdateProgress(T *t, float progress);
    static void UpdateStatus(T *t, const std::string &status);
    static void Done(T *t);
    
    static ThreadInfo* GetThreadInfo(T *t);

protected:
    typedef std::map<T*,ThreadInfo*>ThreadMap;
    typedef typename std::map<T*,ThreadInfo*>::iterator ThreadMapIterator;

    static SDL_mutex *Lock;
    static std::map<T*,ThreadInfo*> Threads;
};

template <typename T>
SDL_mutex* ThreadedFactory<T>::Lock = SDL_CreateMutex();

template <typename T>
std::map<T*,ThreadInfo*> ThreadedFactory<T>::Threads;
    
template <typename T>
T *ThreadedFactory<T>::Load(const std::string &name) {
    T *t = new T();
    Info("Forking load thread");
    ThreadInfo *threadInfo = new ThreadInfo(SDL_CreateThread(ThreadedLoad, t));
    Threads[t] = threadInfo;
    return t;
}

template <typename T>
void ThreadedFactory<T>::Finish(T *t) {
    ThreadInfo *threadInfo;
    if((threadInfo = GetThreadInfo(t))) {
        Threads.erase(t);
        SDL_WaitThread(threadInfo->thread, 0);
        delete threadInfo;
    }
}

template <typename T>
float ThreadedFactory<T>::Progress(T *t) {
    float progress;
    ThreadInfo *threadInfo;
    
    SDL_mutexP(Lock);
    if((threadInfo = GetThreadInfo(t))) {
        progress = threadInfo->progress;
    }
    SDL_mutexV(Lock);
    
    return progress;
}

template <typename T>
std::string ThreadedFactory<T>::Status(T *t) {
    std::string status;
    ThreadInfo *threadInfo; 

    SDL_mutexP(Lock);
    if((threadInfo = GetThreadInfo(t))) {
        status = threadInfo->status;
    }
    SDL_mutexV(Lock);
    
    return status;
}

template <typename T>
bool ThreadedFactory<T>::IsDone(T *t) {
    bool done;
    ThreadInfo *threadInfo;

    SDL_mutexP(Lock);
    if((threadInfo = GetThreadInfo(t))) {
        done = threadInfo->done;
    }
    SDL_mutexV(Lock);
    
    return done;
}

template <typename T>
int ThreadedFactory<T>::ThreadedLoad(void *data) {
    Error("ThreadedLoad not implemented for default ThreadedFactory");
    return 0;
}

template <typename T>
void ThreadedFactory<T>::UpdateProgress(T *t, float progress) {
    SDL_mutexP(Lock);
    Threads[t]->progress = progress;
    SDL_mutexV(Lock);
}

template <typename T>
void ThreadedFactory<T>::UpdateStatus(T *t, const std::string &status) {
    SDL_mutexP(Lock);
    Threads[t]->status = status;
    SDL_mutexV(Lock);    
}

template <typename T>
void ThreadedFactory<T>::Done(T *t) {
    SDL_mutexP(Lock);
    Threads[t]->done = true;
    SDL_mutexV(Lock);    
}

template <typename T>
ThreadInfo* ThreadedFactory<T>::GetThreadInfo(T *t) {
    ThreadMapIterator itr = Threads.find(t);
    if(itr != Threads.end()) {
        return itr->second;
    } else {
        return 0;
    }
}

#endif
