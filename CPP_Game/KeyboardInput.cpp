#include "KeyboardInput.h"

//Resets Key Per Frame
void KeyboardInput::beginNewFrame()
{
    pressedKeys.clear();
    releasedKeys.clear();
}

//Key is RELEASED from keyboard
void KeyboardInput::keyUpEvent(const SDL_Event& event)
{
    this->releasedKeys[event.key.keysym.scancode] = true;
    this->heldKeys[event.key.keysym.scancode] = false;
}

//Key is HELD DOWN from keyboard
void KeyboardInput::keyDownEvent(const SDL_Event& event)
{
    this->pressedKeys[event.key.keysym.scancode] = true;
    this->heldKeys[event.key.keysym.scancode] = true;
}

bool KeyboardInput::wasKeyPressed(SDL_Scancode key)
{
    return this->pressedKeys[key];
}

bool KeyboardInput::wasKeyReleased(SDL_Scancode key)
{
    return this->releasedKeys[key];
}

bool KeyboardInput::isKeyHeld(SDL_Scancode key)
{
    return this->heldKeys[key];
}
