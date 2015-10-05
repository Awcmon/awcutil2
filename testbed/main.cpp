
#include <iostream>
#include <SDL.h>
#undef main
#include <awcutil.h>

#define _USE_MATH_DEFINES
#include <math.h>

using std::cout;
using awcutil::Vector2f;
using awcutil::clamp;
using awcutil::approach;
using awcutil::deg2rad;
using awcutil::rad2deg;
using awcutil::dsin;
using awcutil::dcos;
using awcutil::angd_normalize;
using awcutil::angd_difference;
using awcutil::angd_approach;
using awcutil::angd_forward;
using awcutil::angr_normalize;
using awcutil::angr_difference;
using awcutil::angr_approach;
using awcutil::angr_forward;


int main(int argc, char* args[])
{
	//cout << angr_normalize((float)M_PI);
	awcutils::sdl::Window window("Hi", 640, 480, 0);
	SDL_Delay(10000);
	return 0;
}
