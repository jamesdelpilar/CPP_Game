#include <iostream>
#include "Vec2.h"

Vec2::Vec2() {
	x = 0.0f;
	y = 0.0f;

}
Vec2::Vec2(float x_, float y_) {
	x = x_;
	y = y_;

}
Vec2 Vec2::operator + (const Vec2& v_) const {
	return Vec2((x + v_.x), (y + v_.y));
}
Vec2 Vec2::operator - (const Vec2& v_) const {
	return Vec2((x - v_.x), (y - v_.y));
}
void Vec2::ScalarMultiplication(float scalar) {
	x = x * scalar;
	y = y * scalar;

}
Vec2 Vec2::operator * (const float s) const {
	return Vec2((x * s), (y * s));
}
float Vec2::Mag() {
	return (sqrt((x * x) + (y * y)));
}
void Vec2::Normalize() {
	float denom = 0;
	denom = Mag();
	x = x / denom;
	y = y / denom;

}

