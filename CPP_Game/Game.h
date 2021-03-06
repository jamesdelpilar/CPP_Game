#pragma once

#include <SDL_mixer.h>
#include "BaseEnemy.h"
#include "Enemy.h"
#include "Collision.h"
#include "Graphics.h"
#include "KeyboardInput.h"
#include "Player.h"
#include "SpriteAnimation.h"
#include "Sprite.h"
#include "TileMap.h"
#include "TestEnemy.h"
#include <SDL_mixer.h>

class Collision;
class Graphics;
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

	TestEnemy testEnemy1;
	TestEnemy testEnemy2;
	TestEnemy testEnemy3;
	TestEnemy testEnemy4;
	TestEnemy testEnemy5;

	Player mainPlayer;
	TileMap Level1;
	Sprite gameOver;
	Sprite levelComplete;
	
	Collision collider;

	SDL_Rect bottomWall;
	SDL_Rect topWall;
	SDL_Rect leftWall;
	SDL_Rect rightWall;
};

