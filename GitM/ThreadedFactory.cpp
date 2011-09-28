#include <GitM/ThreadedFactory.h>

ThreadInfo::ThreadInfo(): thread(0), progress(0.0), status("Default"), done(false) {}
ThreadInfo::ThreadInfo(SDL_Thread *nThread): thread(nThread), progress(0.0), status("Default"), done(false) {}