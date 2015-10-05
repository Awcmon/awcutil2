
#ifndef MISC_H
#define MISC_H

#include <vector>
#include <time.h>
#include "vector2f.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace awcutil
{
	float clamp(float val, float min, float max);
	int clamp(int val, int min, int max);
	float approach(float val, float targ, float inc);

	float deg2rad(float val);
	float rad2deg(float val);
	float dsin(float _ang);
	float dcos(float _ang);

	//Degrees
	float angd_normalize(float ang);
	float angd_difference(float a, float b);
	float angd_approach(float cur, float target, float inc);
	Vector2f angd_forward(float ang);

	//Radians
	float angr_normalize(float ang);
	float angr_difference(float a, float b);
	float angr_approach(float cur, float target, float inc);
	Vector2f angr_forward(float ang);
}

#endif
