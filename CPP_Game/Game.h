#pragma once

#include "Collision.h"
#include "BaseEnemy.h"
#include "Graphics.h"
#include "KeyboardInput.h"
#include "Player.h"
#include "SpriteAnimation.h"
#include "TileMap.h"
#include "Collision.h"
#include "Enemy.h"
#include "BaseEnemy.h"
#include "SkeletonEnemy.h"
#include "TestEnemy.h"

//Forward Declaration
class Graphics;
class Collision;
class Player;

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

	//SkeletonEnemy enemy_;
	//Enemy enemy1;
	TestEnemy testEnemy;
	Player mainPlayer;
	TileMap Level1;
	
	Collision collider;

	SDL_Rect bottomWall;
	SDL_Rect topWall;
	SDL_Rect leftWall;
	SDL_Rect rightWall;
};

