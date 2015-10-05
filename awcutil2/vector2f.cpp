
#include "Vector2f.h"

namespace awcutil
{
	Vector2f::Vector2f()
	{
		x = 0.0f;
		y = 0.0f;
	}

	Vector2f::Vector2f(float _x, float _y)
	{
		x = _x;
		y = _y;
	}

	//Add
	Vector2f Vector2f::operator+(const Vector2f & v)
	{
		return Vector2f(x + v.x, y + v.y);
	}

	//Subtract
	Vector2f Vector2f::operator-(const Vector2f & v)
	{
		return Vector2f(x - v.x, y - v.y);
	}

	//Dot product
	float Vector2f::operator*(const Vector2f & v)
	{
		return x*v.x + y*v.y;
	}

	//Scalar multiple
	Vector2f Vector2f::operator*(float fl)
	{
		return Vector2f(x * fl, y * fl);
	}

	//Scalar division
	Vector2f Vector2f::operator/(float fl)
	{
		return Vector2f(x / fl, y / fl);
	}

	bool Vector2f::operator==(const Vector2f & v)
	{
		return (v.x == x) && (v.y == y);
	}

	bool Vector2f::operator!=(const Vector2f & v)
	{
		return (v.x != x) || (v.y != y);
	}

	bool Vector2f::operator<(const Vector2f & v) const
	{
		if (x == v.x)
		{
			return y < v.y;
		}
		return x < v.x;
	}

	float Vector2f::length()
	{
		return sqrt(x*x + y*y);
	}

	float Vector2f::length_sqr()
	{
		return (x*x + y*y);
	}
	
	//Return the normalized vector
	Vector2f Vector2f::normalized()
	{
		float l = length();
		if (l == 0.0f)
		{
			return Vector2f();
		}
		return Vector2f(x, y) / l;
	}

	//Normalize the vector.
	float Vector2f::normalize()
	{
		float l = length();
		if (l == 0.0f)
		{
			x = 0;
			y = 0;
		}
		else
		{
			x /= l;
			y /= l;
		}
		return l;
	}

	//Returns the angle of the vector in radians
	float Vector2f::angle()
	{
		return atan2(y, x);
	}

	float Vector2f::dot(Vector2f _v)
	{
		return (x * _v.x + y * _v.y);
	}

	bool Vector2f::in_between(Vector2f _pos1, Vector2f _pos2)
	{
		if ((x >= _pos1.x && x <= _pos2.x) && (y >= _pos1.y && y <= _pos2.y))
		{
			return true;
		}
		else
		{
			return false;
		}
		return false;
	}

	Vector2f Vector2f::projection_to_axis(Vector2f _axis)
	{
		return _axis*((Vector2f(x, y).dot(_axis)) / (_axis.x * _axis.x + _axis.y * _axis.y));
	}

	float Vector2f::dot(Vector2f _v1, Vector2f _v2)
	{
		return _v1.x*_v2.x + _v1.y*_v2.y;
	}

	Vector2f Vector2f::projection(Vector2f _pos, Vector2f _axis)
	{
		return _axis*(dot(_pos, _axis) / (_axis.x * _axis.x + _axis.y * _axis.y));
	}

	std::ostream & operator<<(std::ostream & os, const Vector2f & v)
	{
		os << "Vector2D( " << v.x << " , " << v.y << " )";
		return os;
	}
}