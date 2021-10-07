#pragma once

#include "Graphics.h"
#include "KeyboardInput.h"
#include "Player.h"
#include "SpriteAnimation.h"
#include "TileMap.h"

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

	TileMap Level1;
	Player mainPlayer;
	//SpriteAnimation mainPlayer;

};

