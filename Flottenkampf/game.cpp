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
	//std::cout << "Fleet 2: " << std::endl;
	//int fleetSize2 = validateFleetSize();

	int fleetSize1 = 1;
	int fleetSize2 = 1;

	// Initialize fleet1 with one Cruiser
	for (int i = 0; i < fleetSize1; ++i)
	{
		this->fleet1.push_back(std::make_unique<Cruiser>());
	}

	// Initialize fleet2 with one Cruiser
	for (int i = 0; i < fleetSize2; ++i)
	{
		this->fleet2.push_back(std::make_unique<Cruiser>());
	}
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
	Ship* attackShip = chooseRandomShip(attackerFleet);
	Ship* defenderShip = chooseRandomShip(defenderFleet);

	if (defenderShip == nullptr || attackShip == nullptr)
	{
		std::cerr << "Error: attacker or defender are initalized with null. " << std::endl << "Cannot proceed with the attack." << std::endl;
		return;
	}
	int attackProb = defenderShip->getSize();
	std::cout << "attackProb: " << attackProb << std::endl;

	if (generateRandomNumber(gen, 1, 10) < attackProb)
	{
		attackShip->attack(*defenderShip);

		if (defenderShip->getHullHP() > 1)
		{
			std::cout << "Ship of type " 
				<< convertShipTypeToString(defenderShip->getShipType()) 
					<< " destroyed" << std::endl;

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
		}
	}
	else
	{
		std::cout << "Attack not successful - next turn..." << std::endl;
	}
}


void Game::handleInput()
{
	std::cout << "Press any key to continue to next round: ";
	_getch();

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
	Ship* chosenShip = chosenFleet[generateRandomNumber(gen, 0, chosenFleet.size() - 1)].get();
	return chosenShip;
}


// for rendering UI and world map for debugging
void Game::render()
{

}

