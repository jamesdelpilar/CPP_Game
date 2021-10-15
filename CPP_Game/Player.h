#pragma once

#include "Globals.h"
#include "SpriteAnimation.h"

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

private:
	float changeInXPos, changeInYPos;
	Direction facingPosition_;

};