#pragma once

#include <string>
#include "Collision.h"
#include "Globals.h"
#include "Player.h"
#include "SpriteAnimation.h"

class Game;
class Graphics;
class Player;

using namespace globals;

class BaseEnemy : public SpriteAnimation
{
public:
	BaseEnemy();
	BaseEnemy(Graphics& graphics, std::string filePath, int srcX, int srcY, int width, int height,
		Vector2 spawnPoint, int timeToUpdate);
	~BaseEnemy();


	virtual void update(int elapsedTime, Player &player);
	virtual void draw(Graphics& graphics);

	virtual void animationComplete(string currentAnimation);
	virtual void setupAnimations();

	// Stops animation and plays idle animation
	void stopMoving();
	void wallColliding();

	// getters & setters
	SDL_Rect getEnemyHitBox() { return enemyHitBox; }
	SDL_Rect getFieldOfView() { return fieldOfView; }
	float getChangeInXPos() { return changeInXPos; }
	float getChangeInYPos() { return changeInYPos; }

	void setChangeInXPos(float changeInXPos_) { changeInXPos = changeInXPos_; }
	void setChangeInYPos(float changeInYPos_) { changeInYPos = changeInYPos_; }

private:
	float changeInXPos, changeInYPos;
	SDL_Rect enemyHitBox;
	SDL_Rect fieldOfView;
	Direction facingPosition_;
};

