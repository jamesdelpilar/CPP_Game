#pragma once

#include "Graphics.h"
#include "KeyboardInput.h"
#include "Player.h"
#include "SpriteAnimation.h"

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

	Player mainPlayer;
	//SpriteAnimation mainPlayer;

};

