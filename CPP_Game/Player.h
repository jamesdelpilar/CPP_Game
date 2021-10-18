#pragma once

#include "Globals.h"
#include "SpriteAnimation.h"
#include "Collision.h"////////////////////////


class Graphics;
enum Globals;

class Player : public SpriteAnimation
{
public:
	Player();
	~Player();
	Player(Graphics& graphics, float x, float y);
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
	void stopMoving();
	void wallColliding();
	// getters & setters
	SDL_Rect getPlayerHitBox() { return playerHitBox; }
	float getChangeInXPos() { return changeInXPos; }
	float getChangeInYPos() { return changeInYPos; }

	void setChangeInXPos(float changeInXPos_) { changeInXPos = changeInXPos_; }
	void setChangeInYPos(float changeInYPos_) { changeInYPos = changeInYPos_; }

private:
	float changeInXPos, changeInYPos;
	SDL_Rect playerHitBox;/////////////////////
	Direction facingPosition_;

};