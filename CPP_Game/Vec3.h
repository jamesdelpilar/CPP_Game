#ifndef VEC3_H
#define VEC3_H

#include <iostream>

class Vec3
{
public:
	float x, y, z;

	Vec3(float, float, float);
	Vec3();

	Vec3 operator + (const Vec3& v) const;
	Vec3 operator - (const Vec3& v) const;
	void ScalarMultiplication(float scalar);
	Vec3 operator * (const float s) const;
	float Mag();
	void Normalize();
	Vec3 Cross(Vec3 otherVec);
	float Dot(Vec3);
	void Lerp(Vec3, float);
	void RotateZ(float);
};

#endif