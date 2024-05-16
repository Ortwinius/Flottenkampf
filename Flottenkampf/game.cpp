#include "game.h"

Game::Game()
	: gameIsRunning(true)
	, rd()
	, gen(rd())
{
	initGame();
}

Game::~Game() = default;

void Game::initGame()
{
	//std::cout << "Fleet 1 : " << std::endl;
	//int fleetSize1 = validateFleetSize();
	//// TODO: init vector for fleet 1 and assign ships to it
	//std::cout << "Fleet 2: " << std::endl;
 //	int fleetSize2 = validateFleetSize();
	//// TODO: init vector for fleet 2 and assign ships to it
	//

	int fleetSize1 = 2;
	int fleetSize2 = 2;

	this->fleet1.resize(fleetSize1);
	this->fleet1.push_back(std::make_unique<Cruiser>());

	this->fleet2.resize(fleetSize2);
	this->fleet2.push_back(std::make_unique<Cruiser>());
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
	// while one ship of both fleets is alive attack each other
	// computer1 chooses ship1 of type Cruiser against ship 8 of type Cruiser
	// computer2 chooses ship9 of type destroyer against ship 2 of type fighter
	
	// if random number between 1, 100 is < 10 attack other ship
	// if its unsuccesful other computer has his turn to attack the ship
	
	// if success: attacking damage of ship1 gets subtracted from hullHP from ship2
	// and if HP < 1 -> ship gets deleted from vec

	// fleet 1
	Ship* currentShip = chooseRandomShip(fleet1);
	Ship* toAttack = chooseRandomShip(fleet2);

	int attackProb = toAttack->getSize();
	if (generateRandomNumber(gen, 1, 100) < attackProb)
	{
		currentShip->attack(*toAttack);
	}
}

void Game::handleInput()
{
	std::cout << "Press any key to continue to next round: ";
	_getch();

}

// for rendering UI and world map for debugging
void Game::render()
{
}

int Game::validateFleetSize()
{
	bool validated = false;
	int size = 0;
	while (!validated)
	{
		std::cout << "Input size of fleet (1-9): ";
		std::cin >> size;
		if (size >= DefaultValues::minFleetShipCount && size < DefaultValues::maxFleetShipCount)
			break;

		std::cout << std::endl << "Invalid size" << std::endl;
	}
	return size;
}

Ship* Game::chooseRandomShip(const Fleet& chosenFleet)
{
	Ship* chosenShip = chosenFleet[generateRandomNumber(gen, 1, chosenFleet.size())].get();
	return chosenShip;
}
