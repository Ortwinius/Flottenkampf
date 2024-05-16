#include "game.h"

Game::Game()
	: gameIsRunning(true)
{
	initGame();
}

Game::~Game() = default;

void Game::initGame()
{
	std::cout << "Fleet 1 : " << std::endl;
	int fleetSize1 = validateFleetSize();
	// TODO: init vector for fleet 1 and assign ships to it
	std::cout << "Fleet 2: " << std::endl;
 	int fleetSize2 = validateFleetSize();
	// TODO: init vector for fleet 2 and assign ships to it
	
}

void Game::run()
{
	while (gameIsRunning)
	{
		handleInput();
		update();
		render();
	}
}

void Game::update()
{
}

void Game::handleInput()
{
}

// for rendering UI and world map for debugging
void Game::render()
{
}

int Game::validateFleetSize()
{
	bool validated = false;
	while (!validated)
	{
		try
		{

		}
		catch (const std::exception& e)
		{

		}
	}
}
