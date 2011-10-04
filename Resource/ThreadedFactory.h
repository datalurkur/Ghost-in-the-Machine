#ifndef THREADEDFACTORY_H
#define THREADEDFACTORY_H

#include <Base/Base.h>
#include <Base/Log.h>

#include <SDL/SDL_mutex.h>
#include <SDL/SDL_thread.h>

#define LOCK_MUTEX \
    do { \
        ASSERT(F::Lock); \
        SDL_mutexP(F::Lock); \
    } while(false)

#define UNLOCK_MUTEX \
    do { \
        SDL_mutexV(F::Lock); \
    } while(false)

struct ThreadInfo {
    SDL_Thread *thread;
    float progress;
    std::string status;
    
    ThreadInfo();
    ThreadInfo(SDL_Thread *nThread);
};

template <typename T>
struct FactoryThreadParams {
	std::string name;
	T *ptr;

	FactoryThreadParams(const std::string &nName, T* nPtr);
};

template <typename T>
FactoryThreadParams<T>::FactoryThreadParams(const std::string &nName, T* nPtr): name(nName), ptr(nPtr) {}

template <typename T, typename F>
class ThreadedFactory {
public:
    static void Setup();
    static void Teardown();

    static T* GetOrLoad(const std::string &name);
    static void Unload(T* t);
	static void Unload(const std::string &name);

    static float Progress(T* t);
    static std::string Status(T* t);
    static bool IsDone(T* t);

    typedef std::map<T*,ThreadInfo> ThreadMap;
    typedef typename ThreadMap::iterator ThreadMapIterator;
    
protected:
    static int ThreadedLoad(void* data);

    static void UpdateProgress(T* t, float progress);
    static void UpdateStatus(T* t, const std::string &status);
    static void Finish(T* t);
    
    static ThreadInfo* GetThreadInfo(T* t);

protected:
    static SDL_mutex* Lock;
    static ThreadMap Threads;

    typedef std::map<std::string, T*> ContentMap;
    static ContentMap Resources;
};

template <typename T, typename F>
SDL_mutex* ThreadedFactory<T,F>::Lock;

template <typename T, typename F>
typename ThreadedFactory<T,F>::ThreadMap ThreadedFactory<T,F>::Threads;

template <typename T, typename F>
typename ThreadedFactory<T,F>::ContentMap ThreadedFactory<T,F>::Resources;

template <typename T, typename F>
void ThreadedFactory<T,F>::Setup() {
    F::Lock = SDL_CreateMutex();
}

template <typename T, typename F>
void ThreadedFactory<T,F>::Teardown() {
    if(F::Lock) {
        SDL_mutexP(F::Lock);

        ThreadMapIterator itr = F::Threads.begin();
        for(; itr != F::Threads.end(); itr++) {
            SDL_KillThread(itr->second.thread);
        }
        F::Threads.clear();

        typename ContentMap::iterator cItr = F::Resources.begin();
        for(; cItr != F::Resources.end(); cItr++) {
            delete (cItr->second);
        }
        F::Resources.clear();

        SDL_mutexV(F::Lock);
        SDL_DestroyMutex(F::Lock);
        F::Lock = 0;
    }
}

template <typename T, typename F>
T* ThreadedFactory<T,F>::GetOrLoad(const std::string &name) {
	T* t = 0;

	LOCK_MUTEX;
	typename ContentMap::iterator itr = F::Resources.begin();
	for(; itr != F::Resources.end(); itr++) {
		if(name == itr->first) {
			t = itr->second;
			break;
		}
	}

	if(!t) {
		t = new T();
		FactoryThreadParams<T> params(name, t);
		Threads[t] = ThreadInfo(SDL_CreateThread(F::ThreadedLoad, (void*)&params));
		F::Resources[name] = t;
	}
    UNLOCK_MUTEX;

    return t;
}

template <typename T, typename F>
void ThreadedFactory<T,F>::Unload(T* t) {
    LOCK_MUTEX;
    typename ContentMap::iterator itr = F::Resources.begin();
    for(; itr != F::Resources.end(); itr++) {
        if(itr->second == t) { break; }
    }
    ASSERT(itr != F::Resources.end());
    F::Resources.erase(itr);
    delete t;
}

template <typename T, typename F>
void ThreadedFactory<T,F>::Unload(const std::string &name) {
    LOCK_MUTEX;
    typename ContentMap::iterator itr = F::Resources.begin();
    for(; itr != F::Resources.end(); itr++) {
        if(itr->first == name) {
            delete (itr->second);
            break;
        }
    }
    ASSERT(itr != F::Resources.end());
    F::Resources.erase(itr);
}

template <typename T, typename F>
void ThreadedFactory<T,F>::Finish(T *t) {
    LOCK_MUTEX;
    F::Threads.erase(t);
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
    F::Finish((T*)data);
    return 0;
}

template <typename T, typename F>
void ThreadedFactory<T,F>::UpdateProgress(T* t, float progress) {
    LOCK_MUTEX;
    F::Threads[t].progress = progress;
    UNLOCK_MUTEX;
}

template <typename T, typename F>
void ThreadedFactory<T,F>::UpdateStatus(T* t, const std::string &status) {
    LOCK_MUTEX;
    F::Threads[t].status = status;
    UNLOCK_MUTEX;
}

// WARNING: This function is not threadsafe, and is designed to be called
//  from within functions that make use of mutex locking
template <typename T, typename F>
ThreadInfo* ThreadedFactory<T,F>::GetThreadInfo(T *t) {
    ThreadMapIterator itr = F::Threads.find(t);
    if(itr != F::Threads.end()) {
        return &(itr->second);
    } else {
        return 0;
    }
}

#undef LOCK_MUTEX
#undef UNLOCK_MUTEX

#endif
