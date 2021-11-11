#pragma once

#include "BaseEnemy.h"
#include "Game.h"
#include "Globals.h"
#include "Player.h"
#include "Vec2.h"

class Game;
class Player;

using namespace globals;

class SkeletonEnemy : public BaseEnemy
{
public:
	SkeletonEnemy();
	SkeletonEnemy(Graphics& graphics, Vector2 spawnPoint);

	void update(int elapsedTime, Player& player);
	void draw(Graphics& graphics);

	virtual void animationComplete(string currentAnimation);
	virtual void setupAnimations();

private:

};

