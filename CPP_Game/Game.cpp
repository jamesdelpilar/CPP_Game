#include "Game.h"

Game::Game() 
{
	// Initializes everything (SDL2, SDL Mixer, SDL TTF, SDL Image)
	SDL_Init(SDL_INIT_EVERYTHING);
	gameloop();
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

	mainPlayer = Sprite(graphics, "Assets/Sprites/Player.png", 0, 0, 32, 32, 0, 0);
	//Starting the gameloop
	while (true)
	{
		//Does this go outside the gameloop?
		//////////////////////////////////////////////
		//Limiting Frame Rate						//
		const int FPS = 60;							//
		const int frameDelay = 1000 / FPS;			//
		Uint32 frameStart;							//
		int frameTime;								//
		//////////////////////////////////////////////

		frameStart = SDL_GetTicks();

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
		if (keyboardInput.keyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

		draw(graphics);
	}
}
				
		
void Game::draw(Graphics& graphics)
{
	graphics.clear();
	mainPlayer.draw(graphics, 0, 0);
	graphics.flip();
}
void Game::update(float elapsedTime)
{

}