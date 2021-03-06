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

	// Start SDL Mixer
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	// Load Audio Files
	Mix_Music* backgroundSound = Mix_LoadMUS("Assets/Sounds/Opening.mp3");
	Mix_Chunk* playerAttack = Mix_LoadWAV("Assets/Sounds/hit.wav");
	Mix_Chunk* playerWalk = Mix_LoadWAV("Assets/Sounds/footsteps.wav");

	// Play Audio Files
	Mix_PlayMusic(backgroundSound, -1);

	// Calling objects

	this->Level1 = TileMap("Level1", Vector2(0,0), graphics);
	this->gameOver = Sprite::Sprite(graphics, "Assets/Sprites/GameOver.png", 0, 0, 1480, 832, 0, 0);
	this->levelComplete = Sprite::Sprite(graphics, "Assets/Sprites/LevelComplete.png", 0, 0, 1480, 833, 0, 0);
	//this->menu = Menu::Menu("Level1", Vector2(0, 0), graphics);
	this->mainPlayer = Player(graphics, 500, 300);

	bottomWall = SDL_Rect{ -60, 630, 1480, 10 };
	topWall = SDL_Rect{ -60, -30, 1480, 10 };
	leftWall = SDL_Rect{ -30, -30, 10, 700 };
	rightWall = SDL_Rect{ 1410, -30, 10, 700 };
	this->testEnemy1 = TestEnemy(graphics, Vector2(100, 50));
	this->testEnemy2 = TestEnemy(graphics, Vector2(950, 350));
	this->testEnemy3 = TestEnemy(graphics, Vector2(150, 500));
	this->testEnemy4 = TestEnemy(graphics, Vector2(1300, 150));
	this->testEnemy5 = TestEnemy(graphics, Vector2(1300, 500));

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
			mainPlayer.getChangeInYPos() == 0.0f ))
		{
			this->mainPlayer.moveLeft();
			Mix_PlayChannel(-1, playerWalk, 0); // SFX
		}

		if ((keyboardInput.isKeyHeld(SDL_SCANCODE_D) == true &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_A) == false) &&
			mainPlayer.getChangeInYPos() == 0.0f))
		{
			this->mainPlayer.moveRight();
			Mix_PlayChannel(-1, playerWalk, 0); // SFX
		}

		if ((keyboardInput.isKeyHeld(SDL_SCANCODE_S) == true &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_W) == false) &&
			mainPlayer.getChangeInXPos() == 0.0f))
		{
			this->mainPlayer.moveDown();
			Mix_PlayChannel(-1, playerWalk, 0); // SFX
		}

		if ((keyboardInput.isKeyHeld(SDL_SCANCODE_W) == true &&
			(keyboardInput.isKeyHeld(SDL_SCANCODE_S) == false) &&
			mainPlayer.getChangeInXPos() == 0.0f))
		{
			this->mainPlayer.moveUp();
			Mix_PlayChannel(-1, playerWalk, 0); // SFX
		}

		else if (!keyboardInput.isKeyHeld(SDL_SCANCODE_A) && !keyboardInput.isKeyHeld(SDL_SCANCODE_D) && !keyboardInput.isKeyHeld(SDL_SCANCODE_S)
			&& !keyboardInput.isKeyHeld(SDL_SCANCODE_W))
			{
			this->mainPlayer.stopMoving(this->mainPlayer.getDir());
			if (keyboardInput.isKeyHeld(SDL_SCANCODE_RETURN) == true && this->mainPlayer.getDir() == Direction::UP)
			{
				this->mainPlayer.attackUp();

				Mix_PlayChannel(-1, playerAttack, 0); // SFX

				if(collider.AABB(mainPlayer.getAttackHitBox(), testEnemy1.getEnemyHitBox()) == true) {
					testEnemy1.hp.Deduct(1);
				}
				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy2.getEnemyHitBox()) == true) {
					testEnemy2.hp.Deduct(1);
				}
				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy3.getEnemyHitBox()) == true) {
					testEnemy3.hp.Deduct(1);
				}
				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy4.getEnemyHitBox()) == true) {
					testEnemy4.hp.Deduct(1);
				}
				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy5.getEnemyHitBox()) == true) {
					testEnemy5.hp.Deduct(1);
				}
			}

			else if (keyboardInput.isKeyHeld(SDL_SCANCODE_RETURN) == true && this->mainPlayer.getDir() == Direction::DOWN)
			{
				this->mainPlayer.attackDown();

				Mix_PlayChannel(-1, playerAttack, 0); // SFX

				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy1.getEnemyHitBox()) == true) {
					testEnemy1.hp.Deduct(1);
				}
				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy2.getEnemyHitBox()) == true) {
					testEnemy2.hp.Deduct(1);
				}
				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy3.getEnemyHitBox()) == true) {
					testEnemy3.hp.Deduct(1);
				}
				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy4.getEnemyHitBox()) == true) {
					testEnemy4.hp.Deduct(1);
				}
				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy5.getEnemyHitBox()) == true) {
					testEnemy5.hp.Deduct(1);
				}
			}

			else if (keyboardInput.isKeyHeld(SDL_SCANCODE_RETURN) == true && this->mainPlayer.getDir() == Direction::LEFT)
			{
				this->mainPlayer.attackLeft();

				Mix_PlayChannel(-1, playerAttack, 0); // SFX

				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy1.getEnemyHitBox()) == true) {
					testEnemy1.hp.Deduct(1);
				}
				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy2.getEnemyHitBox()) == true) {
					testEnemy2.hp.Deduct(1);
				}
				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy3.getEnemyHitBox()) == true) {
					testEnemy3.hp.Deduct(1);
				}
				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy4.getEnemyHitBox()) == true) {
					testEnemy4.hp.Deduct(1);
				}
				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy5.getEnemyHitBox()) == true) {
					testEnemy5.hp.Deduct(1);
				}
			}

			else if (keyboardInput.isKeyHeld(SDL_SCANCODE_RETURN) == true && this->mainPlayer.getDir() == Direction::RIGHT)
			{
				this->mainPlayer.attackRight();

				Mix_PlayChannel(-1, playerAttack, 0); // SFX

				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy1.getEnemyHitBox()) == true) {
					testEnemy1.hp.Deduct(1);
				}
				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy2.getEnemyHitBox()) == true) {
					testEnemy2.hp.Deduct(1);
				}
				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy3.getEnemyHitBox()) == true) {
					testEnemy3.hp.Deduct(1);
				}
				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy4.getEnemyHitBox()) == true) {
					testEnemy4.hp.Deduct(1);
				}
				if (collider.AABB(mainPlayer.getAttackHitBox(), testEnemy5.getEnemyHitBox()) == true) {
					testEnemy5.hp.Deduct(1);
				}
			}
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->draw(graphics);
		/*std::cout << this->mainPlayer.getDir() << std::endl;*/
	}

	// Delete Sound Mixer after Game Loop
	Mix_FreeMusic(backgroundSound);
	Mix_FreeChunk(playerAttack);
	Mix_FreeChunk(playerWalk);
	Mix_CloseAudio();

}


void Game::draw(Graphics& graphics)
{
	graphics.clear();

	this->Level1.draw(graphics);


	if (testEnemy1.hp.IsDead() == false ||
		testEnemy2.hp.IsDead() == false ||
		testEnemy3.hp.IsDead() == false ||
		testEnemy4.hp.IsDead() == false ||
		testEnemy5.hp.IsDead() == false) {
		if (mainPlayer.hp.IsDead() == false) {
			if (testEnemy1.hp.IsDead() == false) { this->testEnemy1.draw(graphics); }
			if (testEnemy2.hp.IsDead() == false) { this->testEnemy2.draw(graphics); }
			if (testEnemy3.hp.IsDead() == false) { this->testEnemy3.draw(graphics); }
			if (testEnemy4.hp.IsDead() == false) { this->testEnemy4.draw(graphics); }
			if (testEnemy5.hp.IsDead() == false) { this->testEnemy5.draw(graphics); }
			this->mainPlayer.draw(graphics);
		}
		if (mainPlayer.hp.IsDead() == true) {
			this->gameOver.draw(graphics, 0, -100);
		}
	}
	else if (testEnemy1.hp.IsDead() == true &&
			 testEnemy2.hp.IsDead() == true &&
			 testEnemy3.hp.IsDead() == true &&
			 testEnemy4.hp.IsDead() == true &&
			 testEnemy5.hp.IsDead() == true)
	{
		this->levelComplete.draw(graphics, 0, -100);
	}
	
	//this->enemy_.draw(graphics);
	//this->enemy1.draw(graphics);
	
	graphics.flip();
}
void Game::update(float elapsedTime)
{

	if (collider.AABB(mainPlayer.getPlayerHitBox(), bottomWall) == true || // wall collisions for the player
		collider.AABB(mainPlayer.getPlayerHitBox(), topWall) == true ||
		collider.AABB(mainPlayer.getPlayerHitBox(), leftWall) == true ||
		collider.AABB(mainPlayer.getPlayerHitBox(), rightWall) == true)
	{
		this->mainPlayer.wallColliding(this->mainPlayer.getDir());
	}
	if (collider.AABB(testEnemy1.getEnemyHitBox(), bottomWall) == true || // wall collision for enemy one
		collider.AABB(testEnemy1.getEnemyHitBox(), topWall) == true ||
		collider.AABB(testEnemy1.getEnemyHitBox(), leftWall) == true ||
		collider.AABB(testEnemy1.getEnemyHitBox(), rightWall) == true)
	{
		this->testEnemy1.wallColliding();
	}
	if (collider.AABB(testEnemy2.getEnemyHitBox(), bottomWall) == true || // wall collision for enemy two
		collider.AABB(testEnemy2.getEnemyHitBox(), topWall) == true ||
		collider.AABB(testEnemy2.getEnemyHitBox(), leftWall) == true ||
		collider.AABB(testEnemy2.getEnemyHitBox(), rightWall) == true)
	{
		this->testEnemy2.wallColliding();
	}
	if (collider.AABB(testEnemy1.getEnemyHitBox(), mainPlayer.getPlayerHitBox()) == true ||
		collider.AABB(testEnemy1.getEnemyHitBox(), testEnemy2.getEnemyHitBox()) == true) { // enemy one player collision/enemy two collision
		testEnemy1.wallColliding();
	}
	if (collider.AABB(testEnemy2.getEnemyHitBox(), mainPlayer.getPlayerHitBox()) == true ||
		collider.AABB(testEnemy2.getEnemyHitBox(), testEnemy1.getEnemyHitBox()) == true) { // enemy two player collision/enemy one collision
		testEnemy2.wallColliding();
	}
	this->mainPlayer.update(elapsedTime);
	if(testEnemy1.hp.IsDead() == false){ this->testEnemy1.update(elapsedTime, this->mainPlayer); }
	if (testEnemy2.hp.IsDead() == false) { this->testEnemy2.update(elapsedTime, this->mainPlayer); }
	if (testEnemy3.hp.IsDead() == false) { this->testEnemy3.update(elapsedTime, this->mainPlayer); }
	if (testEnemy4.hp.IsDead() == false) { this->testEnemy4.update(elapsedTime, this->mainPlayer); }
	if (testEnemy5.hp.IsDead() == false) { this->testEnemy5.update(elapsedTime, this->mainPlayer); }

	this->Level1.update(elapsedTime, this->mainPlayer);

}