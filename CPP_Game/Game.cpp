#include "Game.h"

namespace
{
	const int FPS = 60;
	const int MAX_FRAME_TIME = 1000 / FPS; // 1000ms = 1sec
}

Game::Game()
{
	// Initializes everything (SDL2, SDL Mixer, SDL TTF, SDL Image)
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameloop();
}

Game::~Game()
{

}

void Game::gameloop()
{
	Graphics graphics;
	KeyboardInput keyboardInput;

	// Event Handler per frame
	SDL_Event event;

	// Calling objects
	this->mainPlayer = Player(graphics, 50, 50);
	this->Level1 = TileMap("Level 1", Vector2(0,0), graphics);
 
	//FrameRate
	int LAST_UPDATE_TIME = SDL_GetTicks();

	//Starting the gameloop
	while (true)
	{
		keyboardInput.beginNewFrame();

		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					keyboardInput.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP) {
				keyboardInput.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT) {
				return;
			}
		}
		if (keyboardInput.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
		{
			return;
		}

		else if (keyboardInput.isKeyHeld(SDL_SCANCODE_A) == true)
		{
			this->mainPlayer.moveLeft();
		}
		else if (keyboardInput.isKeyHeld(SDL_SCANCODE_D) == true)
		{
			this->mainPlayer.moveRight();
		}
		else if (keyboardInput.isKeyHeld(SDL_SCANCODE_S) == true)
		{
			this->mainPlayer.moveForward();
		}
		else if (keyboardInput.isKeyHeld(SDL_SCANCODE_W) == true)
		{
			this->mainPlayer.moveBackward();
		}

		if (!keyboardInput.isKeyHeld(SDL_SCANCODE_A) && !keyboardInput.isKeyHeld(SDL_SCANCODE_D) && !keyboardInput.isKeyHeld(SDL_SCANCODE_S)
			&& !keyboardInput.isKeyHeld(SDL_SCANCODE_W))
		{
			this->mainPlayer.stopMoving();
		}



		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->draw(graphics);
	}
}


void Game::draw(Graphics& graphics)
{
	graphics.clear();

	this->Level1.draw(graphics);
	this->mainPlayer.draw(graphics);
	
	graphics.flip();
}
void Game::update(float elapsedTime)
{
	this->mainPlayer.update(elapsedTime);
	this->Level1.update(elapsedTime);
}