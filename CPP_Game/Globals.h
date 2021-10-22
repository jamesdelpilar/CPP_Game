#pragma once

namespace globals
{
	const int SCREEN_WIDTH = 1480;
	const int SCREEN_HEIGHT = 720;
	const float SCALE_SPRITE = 2.0f;

	enum class Direction
	{
		LEFT, RIGHT, UP, DOWN
	};
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



