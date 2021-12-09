#include "Vec3.h"

Vec3::Vec3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vec3::Vec3(float x_, float y_, float z_)
{
	x = x_;
	y = y_;
	z = z_;
}

Vec3 Vec3::operator + (const Vec3& v_) const
{
	return Vec3((x + v_.x), (y + v_.y), (z + v_.z));
}

Vec3 Vec3::operator - (const Vec3& v_) const
{
	return Vec3((x - v_.x), (y - v_.y), (z - v_.z));
}

void Vec3::ScalarMultiplication(float scalar)
{
	x = x * scalar;
	y = y * scalar;
	z = z * scalar;
}

Vec3 Vec3::operator * (const float s) const
{
	return Vec3((x * s), (y * s), (z * s));
}

float Vec3::Mag()
{
	return (sqrt((x*x) + (y*y) + (z*z)));
}

void Vec3::Normalize()
{
	float denom = 0;
	denom = Mag();
	x = x / denom;
	y = y / denom;
	z = z / denom;
}

Vec3 Vec3::Cross(Vec3 v_)
{
	return Vec3(((y * v_.z) - (z * v_.y)), ((z * v_.x) - (x * v_.z)), ((x * v_.y) - (y * v_.x)));
}

float Vec3::Dot(Vec3 v_)
{
	return ((x * v_.x) + (y * v_.y) + (z * v_.z));
}

void Vec3::Lerp(Vec3 v_, float t)
{
	x = ((1 - t) * x) + (t * v_.x);
	y = ((1 - t) * y) + (t * v_.y);
	z = ((1 - t) * z) + (t * v_.z);
}

void Vec3::RotateZ(float angl)
{
	float x1 = (x * cos(angl)) - (y * sin(angl));
	float y1 = (x * sin(angl)) + (y * cos(angl));
	x = x1;
	y = y1;
}