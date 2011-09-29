#ifndef BASE_H
#define BASE_H

#include <string>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <stack>
#include <map>
#include <list>

#include <SDL/SDL.h>

enum {
	PLATFORM_APPLE,
	PLATFORM_WIN32,
	PLATFORM_LINUX
};

#if defined(__APPLE__) && defined(__MACH__)
# define SYS_PLATFORM PLATFORM_APPLE
#elif defined( __WIN32__ ) || defined( _WIN32 )
# define SYS_PLATFORM PLATFORM_WIN32
#else
# define SYS_PLATFORM PLATFORM_LINUX
#endif

#if SYS_PLATFORM == PLATFORM_APPLE
#elif SYS_PLATFORM == PLATFORM_WIN32
# include "Windows.h"
# define sleep(seconds) Sleep(seconds*1000)
#endif

#endif