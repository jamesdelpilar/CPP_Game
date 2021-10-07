#include "SpriteAnimation.h"

SpriteAnimation::SpriteAnimation()
{
	visible_ = true;
	timeToUpdate_ = 0;
	timeElapsed_ = 0;
	frameIndex_ = 0;
	currentAnimationOnce_ = 0;
}

SpriteAnimation::SpriteAnimation(Graphics& graphics, const string& filePath, int srcX, int srcY, int width, int height, float posX, float posY, float timeToUpdate) :
	Sprite(graphics, filePath, srcX, srcY, width, height, posX, posY), frameIndex_(0), timeToUpdate_(timeToUpdate), visible_(true), currentAnimationOnce_(false), currentAnimation_(""), timeElapsed_(0)
{
}

void SpriteAnimation::playAnimation(std::string animation, bool once)
{
	this->currentAnimationOnce_ = once;
	if (this->currentAnimation_ != animation)
	{
		this->currentAnimation_ = animation;
		this->frameIndex_ = 0;
	}
}

void SpriteAnimation::update(int elapsedTime)
{
	Sprite::update();

	this->timeElapsed_ += elapsedTime;
	if (this->timeElapsed_ > this->timeToUpdate_)
	{
		this->timeElapsed_ -= this->timeToUpdate_;
		if (this->frameIndex_ < this->animations_[this->currentAnimation_].size() - 1)
		{
			this->frameIndex_++;
		}
		else
		{
			if (this->currentAnimationOnce_ == true) // Plays last frame = stop visible/animation
			{
				this->setVisible(false);
			}
			this->frameIndex_ = 0;
			this->animationComplete(this->currentAnimation_);
		}
	}
}

void SpriteAnimation::draw(Graphics& graphics, int x, int y)
{


	if (this->visible_)
	{
		SDL_Rect destinationRectangle;
		destinationRectangle.x = x + this->offsets_[this->currentAnimation_].x;
		destinationRectangle.y = y + this->offsets_[this->currentAnimation_].y;
		destinationRectangle.w = this->srcRect.w * globals::SCALE_SPRITE;
		destinationRectangle.h = this->srcRect.h * globals::SCALE_SPRITE;

		SDL_Rect sourcRect = this->animations_[this->currentAnimation_][this->frameIndex_];
		graphics.blitSurface(this->spriteSheet, &sourcRect, &destinationRectangle);
	}
}

void SpriteAnimation::addAnimation(int frames, int x, int y, string name, int width, int height, Vector2 offset)
{
	vector<SDL_Rect> rectangles;
	for (int i = 0; i < frames; i++)
	{
		SDL_Rect newRect = { (i + x) * width, y, width, height };
		rectangles.push_back(newRect);
	}

	this->animations_.insert(std::pair<string, vector<SDL_Rect> >(name, rectangles));
	this->offsets_.insert(std::pair<string, Vector2>(name, offset));
}

void SpriteAnimation::resetAnimations()
{
	this->animations_.clear();
	this->offsets_.clear();
}

void SpriteAnimation::stopAnimation()
{
	this->frameIndex_ = 0;
	this->animationComplete(this->currentAnimation_);
}

void SpriteAnimation::setVisible(bool visible)
{
	this->visible_ = visible;
}