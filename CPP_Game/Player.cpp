#include "Player.h"

namespace PLAYER_CONSTS
{
	constexpr float WALK_SPEED = 0.6f;
}

Player::Player()
{
	facingPosition_ = Direction::DOWN;
	changeInXPos = 0;
	changeInYPos = 0;
	playerHitBox = {static_cast<int>(x_), static_cast<int>(y_), 10, 10};////////////////////////
}

Player::~Player()
{
	/*delete &changeInXPos;
	delete &changeInYPos;*/
	//delete &facingPosition_;
}

Player::Player(Graphics& graphics, float x, float y) : SpriteAnimation(graphics, "Assets/Sprites/PlayerMovement.png", 0, 0, 64, 64, x, y, 100)
{
	facingPosition_ = Direction::DOWN;
	graphics.loadImage("Assets/Sprites/PlayerMovement.png");
	this->setupAnimations();
}

void Player::setupAnimations()
{
	this->addAnimation(1, 0, 192, "IdleUp", 64, 64, Vector2(0, 0));
	this->addAnimation(1, 0, 64, "IdleLeft", 64, 64, Vector2(0, 0));
	this->addAnimation(1, 0, 128, "IdleRight", 64, 64, Vector2(0, 0));
	this->addAnimation(1, 0, 0, "IdleDown", 64, 64, Vector2(0, 0));

	this->addAnimation(4, 0, 192, "MoveUp", 64, 64, Vector2(0, 0));
	this->addAnimation(4, 0, 64, "MoveLeft", 64, 64, Vector2(0, 0));
	this->addAnimation(4, 0, 128, "MoveRight", 64, 64, Vector2(0, 0));
	this->addAnimation(4, 0, 0, "MoveDown", 64, 64, Vector2(0, 0));

	this->addAnimation(4, 0, 510, "AttackUp", 64, 64, Vector2(0, 0));
	this->addAnimation(4, 0, 369, "AttackLeft", 64, 64, Vector2(0, 0));
	this->addAnimation(4, 0, 433, "AttackRight", 64, 64, Vector2(0, 0));
	this->addAnimation(4, 0, 305, "AttackDown", 64, 64, Vector2(0, 0));
}

void Player::animationComplete(string currentAnimation)
{
}
void Player::moveLeft()
{
	this->changeInXPos = -PLAYER_CONSTS::WALK_SPEED;
	this->playAnimation("MoveLeft");
	this->facingPosition_ = Direction::LEFT;
}

void Player::moveRight()
{
	this->changeInXPos = PLAYER_CONSTS::WALK_SPEED;
	this->playAnimation("MoveRight");
	this->facingPosition_ = Direction::RIGHT;
}

void Player::moveDown()
{
	this->changeInYPos = PLAYER_CONSTS::WALK_SPEED;
	this->playAnimation("MoveDown");
	this->facingPosition_ = Direction::DOWN;
}

void Player::moveUp()
{
	this->changeInYPos = -PLAYER_CONSTS::WALK_SPEED;
	this->playAnimation("MoveUp");
	this->facingPosition_ = Direction::UP;
}

void Player::attackUp()
{
	this->playAnimation("AttackUp");
}

void Player::attackDown()
{
		this->playAnimation("AttackDown");
}

void Player::attackLeft()
{
		this->playAnimation("AttackLeft");
}

void Player::attackRight()
{
		this->playAnimation("AttackRight");
}


void Player::stopMoving(Direction facingPosition)
{
	this->changeInXPos = 0.0f;
	this->changeInYPos = 0.0f;

	switch (facingPosition)
	{
		case Direction::LEFT:
			this->playAnimation("IdleLeft");
			break;
		case Direction::RIGHT:
			this->playAnimation("IdleRight");
			break;
		case Direction::UP:
			this->playAnimation("IdleUp");
			break;
		case Direction::DOWN:
			this->playAnimation("IdleDown");
			break;
		default:
			break;
	}

}

// temp solution for wall collisions
void Player::wallColliding() {
	this->setChangeInXPos(this->getChangeInXPos() * -5.0);
	this->setChangeInYPos(this->getChangeInYPos() * -5.0);
}

void Player::update(float elapsedTime)
{
	this->x_ += this->changeInXPos * elapsedTime;
	this->y_ += this->changeInYPos * elapsedTime;
	this->playerHitBox = { static_cast<int>(this->x_), static_cast<int>(this->y_), 32, 32 }; //////////
	SpriteAnimation::update(elapsedTime);
}

void Player::draw(Graphics& graphics)
{
	SpriteAnimation::draw(graphics, this->x_, this->y_);
}
