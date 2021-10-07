#ifndef VEC2_H
#define VEC2_H

class Vec2 {
public:
	float x, y;

	Vec2(float, float);
	Vec2();

	Vec2 operator + (const Vec2& v) const;
	Vec2 operator - (const Vec2& v) const;
	void ScalarMultiplication(float scalar);
	Vec2 operator * (const float s) const;
	float Mag();
	void Normalize();
};

#endif
