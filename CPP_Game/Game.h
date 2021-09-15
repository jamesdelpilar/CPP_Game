#pragma once
#include "Graphics.h"
#include "KeyboardInput.h"
#include "Sprite.h"

//Forward Decleration
class Graphics;

// Info for when the GAME runs
class Game
{
public:
	Game();
	~Game();

private:
	// Loops Every Frame
	void gameloop();
	void draw(Graphics& graphics);
	void update(float elapsedTime);

	Sprite mainPlayer;
};

