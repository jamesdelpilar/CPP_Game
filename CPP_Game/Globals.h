#pragma once

namespace globals
{
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	const float SCALE_SPRITE = 1.0f;
}

// For animation offsets, if necessary
struct Vector2
{
	int x, y;

	Vector2() : x(0), y(0) {}

	Vector2(int x, int y) : x(x), y(y) {}

	// Returns Vector 2 with Zero values
	Vector2 zero()
	{
		return Vector2(0, 0);
	}
};


enum Direction
{
	LEFT, RIGHT, FORWARD, BACKWARD
};