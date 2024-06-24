#include "game.h"

Game::Game()
	: gameIsRunning(true)
	, rd()
	, gen(rd())
{
	srand(time(NULL));
	initGame();
}

// vector of ship pointers is automatically deleted (unique_ptrs) -> no memory leak
Game::~Game() = default;

void Game::initGame()
{
	std::cout << "==================" << std::endl;
	std::cout << "  CLASH OF SHIPS" << std::endl;
	std::cout << "==================" << std::endl << std::endl;

	std::cout << "Fleet 1 : " << std::endl;
	int fleetSize1 = validateFleetSize();

	// Initialize fleet1
	for (int i = 0; i < fleetSize1; ++i)
	{
		addShipToFleet(fleet1);
	}

	std::cout << "Fleet 2: " << std::endl;
	int fleetSize2 = validateFleetSize();
	// Initialize fleet2 
	for (int i = 0; i < fleetSize2; ++i)
	{
		addShipToFleet(fleet2);
	}
}

void Game::run()
{
	while (gameIsRunning)
	{
		//handleInput();
		update();
	}
	showFinalStats();
}

// while one ship of both fleets is alive attack each other
// computer1 chooses ship1 of type Cruiser against ship 8 of type Cruiser
// computer2 chooses ship9 of type destroyer against ship 2 of type fighter
void Game::update()
{
	std::cout << std::endl << "Starting attack from fleet 1..." << std::endl;
	fleetAttack(fleet1, fleet2);
	std::cout << "Starting attack from fleet 2..." << std::endl;
	fleetAttack(fleet2, fleet1);
	
}

// if random number between 1, 100 is < 10 attack other ship
// if its unsuccesful other computer has his turn to attack the ship
// if success: attacking damage of ship1 gets subtracted from hullHP from ship2
// and if HP < 1 -> ship gets deleted from vec
void Game::fleetAttack(Fleet& attackerFleet, Fleet& defenderFleet)
{
	if (defenderFleet.size() < 1 || attackerFleet.size() < 1)
	{
		gameIsRunning = false;
		return;
	}

	Ship* attackShip = chooseShipByIndex(attackerFleet);
	Ship* defenderShip = chooseShipByIndex(defenderFleet);

	if (defenderShip == nullptr || attackShip == nullptr)
	{
		std::cerr << "Error: attacker or defender are initalized with null. " << std::endl << "Cannot proceed with the attack." << std::endl;
		return;
	}

	attackShip->attack(defenderShip);

	if (defenderShip->getHullHP() < 1)
	{
		defenderFleet.erase(
			std::remove_if(
				defenderFleet.begin(), defenderFleet.end(),
				[&defenderShip](const std::unique_ptr<Ship>& ship)
				{
					return ship.get() == defenderShip;
				}
			),
			defenderFleet.end()
		);
		std::cout << "Ship of type "
			<< convertShipTypeToString(defenderShip->getShipType())
			<< " destroyed" << std::endl;
	}
}

void Game::showFleetList(const Fleet& chosenFleet)
{
	std::cout << std::endl;
	for (int i = 0; i < chosenFleet.size(); i++)
	{
		std::cout << i + 1 << ".:" << convertShipTypeToString(chosenFleet[i]->getShipType()) << " - " << chosenFleet[i]->getHullHP() << " HP " << std::endl;
	}
}

void Game::showFinalStats()
{
	int championIndex = fleet1.size() > 0 ? 1 : 2;
	std::cout << "Fleet " << championIndex << " has won a glorious battle!" << std::endl;
}


void Game::handleInput()
{
	std::cout << "Press any key to continue to next round: ";
	_getch();

}

int Game::validateFleetSize()
{
	int size = 0;
	while (true)
	{
		std::cout << "Input size of fleet (1-9): ";
		std::cin >> size;
		if (size >= DefaultValues::minFleetShipCount && size < DefaultValues::maxFleetShipCount)
			break;

		std::cout << std::endl << "Invalid size" << std::endl;
	}
	return size;
}

void Game::addShipToFleet(Fleet& chosenFleet)
{
	int type;
	while (true)
	{
		std::cout << "Choose ship type (1-3): ";
		std::cin >> type;
		if (type >= 1 && type <= 3)
			break;

		std::cout << std::endl << "Invalid type" << std::endl;
	}

	type -= 1; // convert index

	switch (type)
	{
		case ShipType::CruiserType:
			chosenFleet.push_back(std::make_unique<Cruiser>());
			break;
		case ShipType::DestroyerType:
			chosenFleet.push_back(std::make_unique<Destroyer>());
			break;
		case ShipType::FighterType:
			chosenFleet.push_back(std::make_unique<Fighter>());
			break;
	}
}

Ship* Game::chooseShipByIndex(const Fleet& chosenFleet)
{
	int index = 0;
	while (true)
	{
		std::cout << "Choose ship of fleet (1-" << chosenFleet.size() << "): ";
		showFleetList(chosenFleet);
		std::cin >> index;
		if (index >= 1 && index <= chosenFleet.size())
			break;

		std::cout << std::endl << "Invalid index" << std::endl;
	}
	//std::cout << "Chosen ship "
	return chosenFleet[index-1].get();
}

Ship* Game::chooseRandomShip(const Fleet& chosenFleet)
{
	Ship* chosenShip = chosenFleet[generateRandomNumber(gen, 0, chosenFleet.size() - 1)].get();
	return chosenShip;
}
