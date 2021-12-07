#pragma once

#include "Globals.h"
#include "Graphics.h"
#include "BaseEnemy.h"
#include "Player.h"
#include "Collision.h"////////////////////////
#include "Health.h"

class Graphics;
class Player;
using namespace globals;


class TestEnemy : public BaseEnemy
{
public:
	TestEnemy();
	~TestEnemy();
	TestEnemy(Graphics& graphics, Vector2 spawnPoint);
	void draw(Graphics& graphics);
	void update(int elapsedTime, Player& player);

	virtual void animationComplete(string currentAnimation);
	virtual void setupAnimations();

	// Stops animation and plays idle animation
	void stopMoving(Direction facingPosition);
	void wallColliding();
	// getters & setters

	float getPlayerXPos() { return x_; }
	float getPlayerYPos() { return y_; }

	Health hp;

private:
	float startingPosX, startingPosY;

	bool chaseState;
	bool isAttacking;
	bool isMoving;
};

