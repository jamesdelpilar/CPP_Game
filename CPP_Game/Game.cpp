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
	//this->enemy1 = Enemy(graphics, 300, 100);
	this->Level1 = TileMap("Level1", Vector2(0,0), graphics);
	this->mainPlayer = Player(graphics, 500, 500);

	bottomWall = SDL_Rect{ -60, 660, 1480, 10 };
	topWall = SDL_Rect{ -60, -60, 1480, 10 };
	leftWall = SDL_Rect{ -60, -30, 10, 700 };
	rightWall = SDL_Rect{ 1430, -30, 10, 700 };
	this->testEnemy = TestEnemy(graphics, Vector2(100, 100));
	//this->enemy_ = SkeletonEnemy(graphics, Vector2(10,10));


	//FrameRate
	int LAST_UPDATE_TIME = SDL_GetTicks();

	//Starting the gameLoop
	while (true)
	{
		keyboardInput.beginNewFrame();

		// Player Inputs
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

		if ((keyboardInput.isKeyHeld(SDL_SCANCODE_A) == true &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_D) == false) &&
			mainPlayer.getChangeInYPos() == 0.0f 
			 /*&&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_S) == false) &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_W) == false)*/))
		{
			this->mainPlayer.moveLeft();
		}

		if ((keyboardInput.isKeyHeld(SDL_SCANCODE_D) == true &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_A) == false) &&
			mainPlayer.getChangeInYPos() == 0.0f/*&&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_S) == false) &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_W) == false)*/))
		{
			this->mainPlayer.moveRight();
		}

		if ((keyboardInput.isKeyHeld(SDL_SCANCODE_S) == true &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_W) == false) &&
			mainPlayer.getChangeInXPos() == 0.0f/*&&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_A) == false) &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_D) == false)*/))
		{
			this->mainPlayer.moveDown();
		}

		if ((keyboardInput.isKeyHeld(SDL_SCANCODE_W) == true &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_S) == false) &&
			mainPlayer.getChangeInXPos() == 0.0f/*&&
			 (keyboardInput.isKeyHeld(SDL_SCANCODE_D) == false) &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_A) == false)*/))
		{
			this->mainPlayer.moveUp();
		}

		else if (!keyboardInput.isKeyHeld(SDL_SCANCODE_A) && !keyboardInput.isKeyHeld(SDL_SCANCODE_D) && !keyboardInput.isKeyHeld(SDL_SCANCODE_S)
			&& !keyboardInput.isKeyHeld(SDL_SCANCODE_W))
		{
			this->mainPlayer.stopMoving(this->mainPlayer.getDir());
			if (keyboardInput.isKeyHeld(SDL_SCANCODE_RETURN) == true && this->mainPlayer.getDir() == Direction::UP)
			{
				std::cout << "ATTACK UP" << std::endl;
				this->mainPlayer.attackUp();
			}
			else if (keyboardInput.isKeyHeld(SDL_SCANCODE_RETURN) == true && this->mainPlayer.getDir() == Direction::DOWN)
			{
				std::cout << "ATTACK DOWN" << std::endl;
				this->mainPlayer.attackDown();
			}
			else if (keyboardInput.isKeyHeld(SDL_SCANCODE_RETURN) == true && this->mainPlayer.getDir() == Direction::LEFT)
			{
				std::cout << "ATTACK LEFT" << std::endl;
				this->mainPlayer.attackLeft();
			}
			else if (keyboardInput.isKeyHeld(SDL_SCANCODE_RETURN) == true && this->mainPlayer.getDir() == Direction::RIGHT)
			{
				std::cout << "ATTACK RIGHT" << std::endl;
				this->mainPlayer.attackRight();
			}
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->draw(graphics);

		/*std::cout << this->mainPlayer.getDir() << std::endl;*/
	}
}


void Game::draw(Graphics& graphics)
{
	graphics.clear();

	this->Level1.draw(graphics);
	this->testEnemy.draw(graphics);
	this->mainPlayer.draw(graphics);
	//this->enemy_.draw(graphics);
	//this->enemy1.draw(graphics);
	
	graphics.flip();
}
void Game::update(float elapsedTime)
{

	if (collider.AABB(mainPlayer.getPlayerHitBox(), bottomWall) == true ||
		collider.AABB(mainPlayer.getPlayerHitBox(), topWall) == true ||
		collider.AABB(mainPlayer.getPlayerHitBox(), leftWall) == true ||
		collider.AABB(mainPlayer.getPlayerHitBox(), rightWall) == true)
	{
		this->mainPlayer.wallColliding(this->mainPlayer.getDir());
		printf("Collision!\n");
	}
	this->mainPlayer.update(elapsedTime);
	this->testEnemy.update(elapsedTime, this->mainPlayer);

	//this->enemy_.update(elapsedTime, mainPlayer);
	//this->enemy1.update(elapsedTime);
	this->Level1.update(elapsedTime, this->mainPlayer);
}