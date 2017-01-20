
#include "misc.h"

namespace awcutil
{
	float clamp(float val, float min, float max)
	{
		if (val > max)
		{
			return max;
		}
		else if (val < min)
		{
			return min;
		}
		return val;
	}

	int clamp(int val, int min, int max)
	{
		if (val > max)
		{
			return max;
		}
		else if (val < min)
		{
			return min;
		}
		return val;
	}

	float approach(float val, float targ, float inc)
	{
		if (val < targ)
		{
			if ((val + inc) < targ)
			{
				val = val + inc;
			}
			else
			{
				val = targ;
			}
		}
		else if (val > targ)
		{
			if ((val + inc) > targ)
			{
				val = val - inc;
			}
			else
			{
				val = targ;
			}
		}
		else
		{
			val = targ;
		}

		return val;
	}

	float deg2rad(float val)
	{
		val = (val / 180)*((float)M_PI);
		return val;
	}
	float rad2deg(float val)
	{
		val = ((val * 180) / ((float)M_PI));
		return (float)val;
	}
	float dsin(float _ang)
	{
		return sin(deg2rad(_ang));
	}
	float dcos(float _ang)
	{
		return cos(deg2rad(_ang));
	}

	float angd_normalize(float ang)
	{
		return (float)(fmod((ang + 180.0f), 360.0f) - 180.0f);
	}
	float angd_difference(float a, float b)
	{
		float diff = angd_normalize(a - b);
		if (diff < 180)
		{
			return diff;
		}
		return diff - 360;
	}
	float angd_approach(float cur, float target, float inc)
	{
		float diff = angd_difference(target, cur);
		return approach(cur, cur + diff, inc);
	}
	Vector2f angd_forward(float ang)
	{
		return Vector2f(dcos(angd_normalize(ang)), dsin(angd_normalize(ang)));
	}

	float angr_normalize(float ang)
	{
		return (float)(fmod((ang + (M_PI_2)), M_PI) - M_PI_2);
	}
	float angr_difference(float a, float b)
	{
		float diff = angr_normalize(a - b);
		if (diff < M_PI_2)
		{
			return diff;
		}
		return (float)(diff - M_PI);
	}
	float angr_approach(float cur, float target, float inc)
	{
		float diff = angr_difference(target, cur);
		return approach(cur, cur + diff, inc);
	}
	Vector2f angr_forward(float ang)
	{
		return Vector2f(cos(angr_normalize(ang)), sin(angr_normalize(ang)));
	}
}
