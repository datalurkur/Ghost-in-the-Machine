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
    
    ThreadInfo();
};

template <typename T, typename F>
class ThreadedFactory {
public:
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
T* ThreadedFactory<T,F>::Load(const std::string &name) {
    T* t = new T();
    Threads[t] = ThreadInfo();
    Threads[t].thread = SDL_CreateThread(F::ThreadedLoad, t);
    return t;
}

template <typename T, typename F>
void ThreadedFactory<T,F>::Finish(T *t) {
    SDL_mutexP(Lock);
    Threads.erase(t);
	SDL_mutexV(Lock);
}

template <typename T, typename F>
float ThreadedFactory<T,F>::Progress(T *t) {
    float progress;
    ThreadInfo* threadInfo;
    
    SDL_mutexP(Lock);
    if((threadInfo = GetThreadInfo(t))) {
        progress = threadInfo->progress;
    }
    SDL_mutexV(Lock);
    
    return progress;
}

template <typename T, typename F>
std::string ThreadedFactory<T,F>::Status(T *t) {
    std::string status;
    ThreadInfo* threadInfo; 

    SDL_mutexP(Lock);
    if((threadInfo = GetThreadInfo(t))) {
        status = threadInfo->status;
    }
    SDL_mutexV(Lock);
    
    return status;
}

template <typename T, typename F>
bool ThreadedFactory<T,F>::IsDone(T *t) {
    bool done;

    SDL_mutexP(Lock);
    done = !GetThreadInfo(t);
    SDL_mutexV(Lock);
    
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
    SDL_mutexP(Lock);
    Threads[t].progress = progress;
    SDL_mutexV(Lock);
}

template <typename T, typename F>
void ThreadedFactory<T,F>::UpdateStatus(T* t, const std::string &status) {
    SDL_mutexP(Lock);
    Threads[t].status = status;
    SDL_mutexV(Lock);    
}

template <typename T, typename F>
ThreadInfo* ThreadedFactory<T,F>::GetThreadInfo(T *t) {
    ThreadMapIterator itr = Threads.find(t);
    if(itr != Threads.end()) {
        return &(itr->second);
    } else {
        return 0;
    }
}

#endif
