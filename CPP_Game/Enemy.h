//#pragma once
//
//#include "Globals.h"
//#include "SpriteAnimation.h"
//#include "Collision.h"
//
//
//class Graphics;
//enum Globals;
//
//class Enemy : public SpriteAnimation
//{
//public:
//	Enemy();
//	~Enemy();
//	Enemy(Graphics& graphics, float x, float y);
//	void draw(Graphics& graphics);
//	void update(float elapsedTime);
//
//	virtual void animationComplete(string currentAnimation);
//	virtual void setupAnimations();
//
//	// Stops animation and plays idle animation
//	void stopMoving();
//	void wallColliding();
//	// getters & setters
//	SDL_Rect getPlayerHitBox() { return playerHitBox; }
//	float getChangeInXPos() { return changeInXPos; }
//	float getChangeInYPos() { return changeInYPos; }
//
//	void setChangeInXPos(float changeInXPos_) { changeInXPos = changeInXPos_; }
//	void setChangeInYPos(float changeInYPos_) { changeInYPos = changeInYPos_; }
//
//private:
//	float changeInXPos, changeInYPos;
//	SDL_Rect playerHitBox;/////////////////////
//	Direction facingPosition_;
//};

