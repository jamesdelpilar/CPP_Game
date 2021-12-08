#include "Enemy.h"

Enemy::Enemy()
{
	facingPosition_ = Direction::DOWN;
	changeInXPos = 0;
	changeInYPos = 0;
	//playerHitBox = { static_cast<int>(x_), static_cast<int>(y_), 10, 10 };////////////////////////
}

Enemy::~Enemy()
{

}

Enemy::Enemy(Graphics& graphics, float x, float y) : SpriteAnimation(graphics, "Assets/Sprites/Skeleton_RedEye.png", 0, 0, 64, 64, x, y, 100)
{
	facingPosition_ = Direction::DOWN;
	graphics.loadImage("Assets/Sprites/Skeleton_RedEye.png");
	this->setupAnimations();
}

void Enemy::setupAnimations()
{
	this->addAnimation(3, 0, 0, "MoveUp", 24, 32, Vector2(0, 0));
	this->addAnimation(3, 0, 32, "MoveRight", 24, 32, Vector2(0, 0));
	this->addAnimation(3, 0, 64, "MoveDown", 24, 32, Vector2(0, 0));
	this->addAnimation(3, 0, 96, "MoveLeft", 24, 32, Vector2(0, 0));
}

void Enemy::animationComplete(string currentAnimation)
{
}

// Wall collisions
void Enemy::wallColliding()
{
	this->setChangeInXPos(this->getChangeInXPos() * -5.0);
	this->setChangeInYPos(this->getChangeInYPos() * -5.0);
}

void Enemy::update(float elapsedTime)
{
	this->x_ += this->changeInXPos * elapsedTime;
	this->y_ += this->changeInYPos * elapsedTime;
	//this->playerHitBox = { static_cast<int>(this->x_), static_cast<int>(this->y_), 32, 32 }; //////////
	SpriteAnimation::update(elapsedTime);
	printf("player HP = %d\n", hp.getHP());
}

void Enemy::draw(Graphics& graphics)
{
	SpriteAnimation::draw(graphics, this->x_, this->y_);
}
