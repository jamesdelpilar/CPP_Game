#pragma once

#include "Collision.h"
#include "BaseEnemy.h"
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

	Player mainPlayer;
	TileMap Level1;
	//Enemy enemy1;
	Collision collider;

};

