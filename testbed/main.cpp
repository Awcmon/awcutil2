
#include <iostream>
#include <awcutil.h>

#define _USE_MATH_DEFINES
#include <math.h>

using std::cout;
using awcutil::Vector2f;

int main()
{
	Vector2f a(420, 420);
	a.normalize();
	cout << M_PI;
	return 0;
}
