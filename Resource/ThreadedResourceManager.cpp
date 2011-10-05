#include <Resource/ThreadedResourceManager.h>

ThreadInfo::ThreadInfo(): thread(0), progress(0.0), status("Default") {}
ThreadInfo::ThreadInfo(SDL_Thread *nThread): thread(nThread), progress(0.0), status("Default") {}
