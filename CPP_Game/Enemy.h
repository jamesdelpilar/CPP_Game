#pragma once

#include "Collision.h"
#include "Globals.h"
#include "Graphics.h"
#include "Health.h"
#include "SpriteAnimation.h"

class Graphics;

using namespace globals;

class Enemy : public SpriteAnimation
{
public:
	Enemy();
	~Enemy();
	Enemy(Graphics& graphics, float x, float y);
	void draw(Graphics& graphics);
	void update(float elapsedTime);

	virtual void animationComplete(string currentAnimation);
	virtual void setupAnimations();

	//Moves player by change in x and y Position
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	//Allows player to switch from moving animations to attacking animations
	void attackUp();
	void attackDown();
	void attackRight();
	void attackLeft();

	// Stops animation and plays idle animation
	void stopMoving(Direction facingPosition);
	void wallColliding();
	// getters & setters
	SDL_Rect getPlayerHitBox() { return playerHitBox; }
	float getChangeInXPos() { return changeInXPos; }
	float getChangeInYPos() { return changeInYPos; }

	float getPlayerXPos() { return x_; }
	float getPlayerYPos() { return y_; }

	void setChangeInXPos(float changeInXPos_) { changeInXPos = changeInXPos_; }
	void setChangeInYPos(float changeInYPos_) { changeInYPos = changeInYPos_; }

	Direction getDir() { return facingPosition_; }

	Health hp;

private:
	float changeInXPos, changeInYPos;
	float x; float y;
	SDL_Rect playerHitBox;
	Direction facingPosition_;
};

