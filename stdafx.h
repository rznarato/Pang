#ifndef _STDAFX_H_
#define _STDAFX_H_

//=============================================================================
#ifdef _WIN32

#pragma pack(1)
#pragma warning(disable:4996) // Using open/close/read... for file access

// Including SDKDDKVer.h defines the highest available Windows platform.
// If you wish to build your application for a previous Windows platform, include WinSDKVer.h and
// set the _WIN32_WINNT macro to the platform you wish to support before including SDKDDKVer.h.
#include <SDKDDKVer.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <gl/gl.h>
#include <GL/glu.h>


#ifdef SWALIB_SOUND
#include <al.h>
#include <alc.h>
#endif //SWALIB_SOUND

#include <io.h>

//=============================================================================
#elif defined(__APPLE__)

#include "TargetConditionals.h"

#if defined(__MACH__) && TARGET_OS_MAC && !TARGET_OS_IPHONE
#include <unistd.h>
#include <GL/glfw.h>

#define GL_BGRA_EXT GL_BGRA

#include <OpenAL/al.h>
#include <OpenAL/alc.h>


#endif
#endif

//=============================================================================
// PNG loading library
#include "lodepng.h"

//=============================================================================
// Common includes
#include <timeapi.h> 
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <vector>
#include <math.h>
// Common defines
#define WORLD_WIDTH        640
#define WORLD_HEIGHT       480
#define START_SIZE         100
#define BUBBLES            14
#define ACCELERATION       0.2f
#define VELOCITY           200
#define FLOOR              20
#define SHURIKEN_SIZE      30
#define SHURIKEN_VELOCITY  300
#define OFFSET_WALL        25
#define PLAYER_X           200
#define PLAYER_Y           50
#define PLAYER_SIZE        60
#define SCORE              1000
#define BUBBLE_RESIZE      25
#endif
