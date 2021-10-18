#pragma once

#include "Collision.h"
#include "Enemy.h"
#include "Graphics.h"
#include "KeyboardInput.h"
#include "Player.h"
#include "SpriteAnimation.h"
#include "TileMap.h"
#include "Collision.h"

//Forward Declaration
class Graphics;
class Collision;

// Info for when the GAME runs
class Game
{
public:
	Game();
	~Game();

private:
	// Loops Every Frame
	void gameLoop();
	void draw(Graphics& graphics);
	void update(float elapsedTime);

	TileMap Level1;
	Player mainPlayer;
	//Enemy enemy1;
	Collision collider;

};

