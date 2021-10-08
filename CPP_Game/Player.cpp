#include "Player.h"

namespace PLAYER_CONSTS
{
	constexpr float WALK_SPEED = 0.4f;
}

Player::Player()
{
	changeInXPos = 0;
	changeInYPos = 0;
	facingPosition_ = LEFT;
}

Player::~Player()
{
	/*delete &changeInXPos;
	delete &changeInYPos;
	delete &facingPosition_;*/
}

Player::Player(Graphics& graphics, float x, float y) : SpriteAnimation(graphics, "Assets/Sprites/Player.png", 0, 0, 32, 32, x, y, 100)
{
	graphics.loadImage("Assets/Sprites/Player.png");
	this->setupAnimations();
	//this->playAnimation("MoveBackward");
}

void Player::setupAnimations()
{
	this->addAnimation(1, 0, 0, "IdleForward", 32, 32, Vector2(0, 0));
	this->addAnimation(1, 0, 32, "IdleLeft", 32, 32, Vector2(0, 0));
	this->addAnimation(1, 0, 64, "IdleRight", 32, 32, Vector2(0, 0));
	this->addAnimation(1, 0, 96, "IdleBackward", 32, 32, Vector2(0, 0));

	this->addAnimation(3, 0, 0, "MoveForward", 32, 32, Vector2(0, 0));
	this->addAnimation(3, 0, 32, "MoveLeft", 32, 32, Vector2(0, 0));
	this->addAnimation(3, 0, 64, "MoveRight", 32, 32, Vector2(0, 0));
	this->addAnimation(3, 0, 96, "MoveBackward", 32, 32, Vector2(0, 0));

}

void Player::animationComplete(string currentAnimation)
{
}
void Player::moveLeft()
{
	this->changeInXPos = -PLAYER_CONSTS::WALK_SPEED;
	this->playAnimation("MoveLeft");
	this->facingPosition_ = LEFT;
}

void Player::moveRight()
{
	this->changeInXPos = PLAYER_CONSTS::WALK_SPEED;
	this->playAnimation("MoveRight");
	this->facingPosition_ = RIGHT;
}

void Player::moveForward()
{
	this->changeInYPos = PLAYER_CONSTS::WALK_SPEED;
	this->playAnimation("MoveForward");
	this->facingPosition_ = FORWARD;
}

void Player::moveBackward()
{
	this->changeInYPos = -PLAYER_CONSTS::WALK_SPEED;
	this->playAnimation("MoveBackward");
	this->facingPosition_ = BACKWARD;
}

void Player::stopMoving()
{
	this->changeInXPos = 0.0f;
	this->changeInYPos = 0.0f;


	//this->playAnimation(this->facingPosition_ == RIGHT ? "IdleRight" : "IdleLeft" || this->facingPosition_ == FORWARD ? "IdleForward" : "IdleBackward");


	this->playAnimation(this->facingPosition_ == RIGHT ? "IdleRight" : "IdleLeft");
	this->playAnimation(this->facingPosition_ == FORWARD ? "IdleForward" : "IdleBackward");

}


void Player::update(float elapsedTime)
{
	this->x_ += this->changeInXPos * elapsedTime;
	this->y_ += this->changeInYPos * elapsedTime;

	SpriteAnimation::update(elapsedTime);
}

void Player::draw(Graphics& graphics)
{
	SpriteAnimation::draw(graphics, this->x_, this->y_);
}
