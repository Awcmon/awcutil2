
#ifndef VECTOR2F_H
#define VECTOR2F_H

#include <math.h>
#include <iostream>

#ifdef BOX2D_H
#include "Box2D/Box2D.h"
#endif

namespace awcutil 
{

	class Vector2f 
	{
	public:
		float x, y;

		//Constructor
		Vector2f();
		Vector2f(float _x, float _y);
		//Overloads
		Vector2f operator+(const Vector2f &v);
		Vector2f operator-(const Vector2f &v);
		float operator*(const Vector2f &v);
		Vector2f operator*(float fl);
		Vector2f operator/(float fl);
		bool operator==(const Vector2f &v);
		bool operator!=(const Vector2f &v);
		bool operator<(const Vector2f &v) const;
		friend std::ostream& operator<<(std::ostream& os, const Vector2f &v);
		//Funcs
		float length();
		float length_sqr();
		Vector2f normalized();
		float normalize();
		float angle();
		float dot(Vector2f _v);
		bool in_between(Vector2f _pos1, Vector2f _pos2);
		Vector2f projection_to_axis(Vector2f _axis);

		//Globals here because I'm lazy and want to just do using awcutil::vector and be done with it.
		float dot(Vector2f _v1, Vector2f _v2);
		Vector2f projection(Vector2f _pos, Vector2f _axis);
	};

	

#ifdef BOX2D_H
	Vector2f b2a(b2Vec2 bv);
	b2Vec2 a2b(Vector2f av);
#endif
} //namespace awcutil

#endif //VECTOR2F_H
