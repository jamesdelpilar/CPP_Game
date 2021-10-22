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

Player::Player(Graphics& graphics, float x, float y) : SpriteAnimation(graphics, "Assets/Sprites/LinkSprite.png", 0, 0, 21, 27, x, y, 100)
{
	facingPosition_ = Direction::DOWN;
	graphics.loadImage("Assets/Sprites/LinkSprite.png");
	this->setupAnimations();
}

void Player::setupAnimations()
{
	this->addAnimation(1, 0, 28, "IdleUp", 21, 26, Vector2(0, 0));
	this->addAnimation(1, 0, 81, "IdleLeft", 21, 25, Vector2(0, 0));
	this->addAnimation(1, 0, 54, "IdleRight", 20, 26, Vector2(0, 0));
	this->addAnimation(1, 0, 0, "IdleDown", 21, 27, Vector2(0, 0));

	this->addAnimation(7, 0, 27, "MoveUp", 21, 27, Vector2(0, 0));
	this->addAnimation(7, 0, 81, "MoveLeft", 21, 25, Vector2(0, 0));
	this->addAnimation(7, 0, 54, "MoveRight", 21, 25, Vector2(0, 0));
	this->addAnimation(7, 0, 0, "MoveDown", 21, 26, Vector2(0, 0));

	this->addAnimation(1, 0, 222, "AttackUp", 25, 35, Vector2(0, 0));
	this->addAnimation(1, 0, 197, "AttackLeft", 35, 25, Vector2(0, 0));
	this->addAnimation(1, 0, 173, "AttackRight", 35, 25, Vector2(0, 0));
	this->addAnimation(1, 0, 137, "AttackDown", 25, 35, Vector2(0, 0));
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
