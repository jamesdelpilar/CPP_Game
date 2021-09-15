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
   releasedKeys[event.key.keysym.scancode] = true;
    heldKeys[event.key.keysym.scancode] = false;
}

//Key is HELD DOWN from keyboard
void KeyboardInput::keyDownEvent(const SDL_Event& event)
{
    pressedKeys[event.key.keysym.scancode] = true;
    heldKeys[event.key.keysym.scancode] = true;
}

bool KeyboardInput::keyPressed(SDL_Scancode key)
{
    return pressedKeys[key];
}

bool KeyboardInput::keyReleased(SDL_Scancode key)
{
    return releasedKeys[key];
}

bool KeyboardInput::isKeyHeld(SDL_Scancode key)
{
    return heldKeys[key];
}
