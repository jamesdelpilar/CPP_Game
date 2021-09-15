#pragma once
#include <map>
#include <SDL.h>

using std::map;

class KeyboardInput
{
public:
	void beginNewFrame();
	void keyUpEvent(const SDL_Event& event);
	void keyDownEvent(const SDL_Event& event);

	bool keyPressed(SDL_Scancode key);
	bool keyReleased(SDL_Scancode key);
	bool isKeyHeld(SDL_Scancode key);

private:
	//Allows for pressed, released or held key presses on the keyboard
	map<SDL_Scancode, bool> pressedKeys;
	map<SDL_Scancode, bool> releasedKeys;
	map<SDL_Scancode, bool> heldKeys;

};

