#pragma once

#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>
#include <random>
#include <algorithm>
#include <conio.h>
#include <exception>

#include "common.h"
#include "ship.h"
#include "cruiser.h"
#include "destroyer.h"
#include "fighter.h"

class Game
{
public:
	Game();
	~Game();

	void run();
private:
	typedef std::vector<std::unique_ptr<Ship>> Fleet;
	typedef std::mt19937 RandGen;

	Fleet fleet1;
	Fleet fleet2;
	bool gameIsRunning;
	std::random_device rd;
	RandGen gen;


	void initGame();
	void update();
	void handleInput();
	void fleetAttack(Fleet& attackerFleet, Fleet& defenderFleet);
	void showFleetList(const Fleet& chosenFleet);
	void showFinalStats();
	int validateFleetSize();
	void addShipToFleet(Fleet& chosenFleet);
	Ship* chooseShipByIndex(const Fleet& chosenFleet);
	Ship* chooseRandomShip(const Fleet& chosenFleet);
};