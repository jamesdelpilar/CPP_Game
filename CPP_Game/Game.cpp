#include "Game.h"

namespace
{
	constexpr int FPS = 60;
	constexpr int MAX_FRAME_TIME = 1000 / FPS; // 1000ms = 1sec
}

Game::Game()
{
	// Initializes everything (SDL2, SDL Mixer, SDL TTF, SDL Image)
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game()
{
	
}

void Game::gameLoop()
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

	//Starting the gameLoop
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

		if ((keyboardInput.isKeyHeld(SDL_SCANCODE_A) == true   && 
			(keyboardInput.isKeyHeld(SDL_SCANCODE_D) == false) && 
			(keyboardInput.isKeyHeld(SDL_SCANCODE_S) == false) && 
			(keyboardInput.isKeyHeld(SDL_SCANCODE_W) == false)))
		{
			this->mainPlayer.moveLeft();
		}

		if ((keyboardInput.isKeyHeld(SDL_SCANCODE_D) == true &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_A) == false) &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_S) == false) &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_W) == false)))
		{
			this->mainPlayer.moveRight();
		}

		if ((keyboardInput.isKeyHeld(SDL_SCANCODE_S) == true &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_D) == false) &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_A) == false) &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_W) == false)))
		{
			this->mainPlayer.moveUp();
		}

		if ((keyboardInput.isKeyHeld(SDL_SCANCODE_W) == true &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_D) == false) &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_S) == false) &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_A) == false)))
		{
			this->mainPlayer.moveDown();
		}

		if (keyboardInput.isKeyHeld(SDL_SCANCODE_RETURN) == true)
		{
			std::cout << "Key Pressed" << std::endl;
			this->mainPlayer.attackDown();
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