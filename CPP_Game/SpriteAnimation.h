#pragma once

#include <map>
#include <string>
#include <vector>
#include "Globals.h"
#include "Graphics.h"
#include "Sprite.h"

using std::map;
using std::string;
using std::vector;

class Graphics;

class SpriteAnimation : public Sprite
{

public:
	SpriteAnimation();
	SpriteAnimation(Graphics& graphics, const string& filePath, int srcX, int srcY, int width, int height,
		float posX, float posY, float timeToUpdate);

	// Playing animations from spritesheet | Bool once allows for looping animation
	void playAnimation(string animation, bool once = false);

	//Update animation with timer
	void update(int elapsedTime);

	//Draw sprite to screen
	void draw(Graphics& graphics, int x, int y);

protected:
	double timeToUpdate_;
	bool currentAnimationOnce_;
	string currentAnimation_;


	// Add animation to map of animations
	void addAnimation(int frames, int x, int y, string name, int width, int height, Vector2 offset);

	void resetAnimations();

	void stopAnimation();

	void setVisible(bool visible);

	virtual void animationComplete(string currentAnimation) = 0;

	virtual void setupAnimations() = 0;

private:
	//Map of animations
	map<string, vector<SDL_Rect> > animations_;
	map<string, Vector2> offsets_;

	int frameIndex_;
	double timeElapsed_;
	bool visible_;
};