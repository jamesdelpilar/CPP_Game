#pragma once

#include "Globals.h"
#include "Graphics.h"
#include "SpriteAnimation.h"
#include "Player.h"
#include "Collision.h"////////////////////////
#include "Health.h"

class Graphics;
class Player;
using namespace globals;


class TestEnemy : public SpriteAnimation
{
public:
	TestEnemy();
	~TestEnemy();
	TestEnemy(Graphics& graphics, float x, float y);
	void draw(Graphics& graphics);
	void update(int elapsedTime, Player& player);

	virtual void animationComplete(string currentAnimation);
	virtual void setupAnimations();

	////Moves player by change in x and y Position
	//void moveUp();
	//void moveDown();
	//void moveRight();
	//void moveLeft();

	////Allows player to switch from moving animations to attacking animations
	//void attackUp();
	//void attackDown();
	//void attackRight();
	//void attackLeft();

	// Stops animation and plays idle animation
	void stopMoving(Direction facingPosition);
	void wallColliding();
	// getters & setters
	SDL_Rect getPlayerHitBox() { return playerHitBox; }
	float getChangeInXPos() { return changeInXPos; }
	float getChangeInYPos() { return changeInYPos; }
	SDL_Rect getEnemyHitBox() { return enemyHitBox; }
	SDL_Rect getFieldOfView() { return fieldOfView; }

	float getPlayerXPos() { return x_; }
	float getPlayerYPos() { return y_; }

	void setChangeInXPos(float changeInXPos_) { changeInXPos = changeInXPos_; }
	void setChangeInYPos(float changeInYPos_) { changeInYPos = changeInYPos_; }

	Direction getDir() { return facingPosition_; }

	Health hp;

private:
	float changeInXPos, changeInYPos;
	float x; float y;
	SDL_Rect playerHitBox;/////////////////////
	Direction facingPosition_;
	SDL_Rect enemyHitBox;/////////////////////
	SDL_Rect fieldOfView;
	bool chaseState;
	bool isAttacking;
	bool isMoving;
};

