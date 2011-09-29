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

#include <SDL.h>

#define	PLATFORM_APPLE 0
#define PLATFORM_WIN32 1
#define	PLATFORM_LINUX 2

#if defined(__APPLE__) && defined(__MACH__)
# define SYS_PLATFORM PLATFORM_APPLE
#elif defined( __WIN32__ ) || defined( _WIN32 )
# define SYS_PLATFORM PLATFORM_WIN32
#else
# define SYS_PLATFORM PLATFORM_LINUX
#endif

#if SYS_PLATFORM == PLATFORM_APPLE
# define ASSERT_FUNCTION __asm__("int $03")
#else
# define ASSERT_FUNCTION __asm { int 3 }
#endif

#define ASSERT(conditional) \
    do { \
        if(!conditional) { \
			ASSERT_FUNCTION; \
		} \
    } while(false)

#if SYS_PLATFORM == PLATFORM_WIN32
# include "Windows.h"
# define sleep(seconds) Sleep(seconds*1000)
#endif

#endif