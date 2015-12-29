
#ifndef AWCUTIL_H
#define AWCUTIL_H

#include "misc.h"
#include "vector2f.h"

//#ifdef _SDL_H
#ifdef _AWCUTIL_SDL
#include "Window.h"
#include "EventContainer.h"
#endif

#ifdef _AWCUTIL_OPENGL
#include "Shader.h"
#include "Mesh.h"
#endif

#endif
