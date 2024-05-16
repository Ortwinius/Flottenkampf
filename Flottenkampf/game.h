#pragma once

#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>
#include <random>
#include <conio.h>

#include "common.h"
#include "ship.h"
#include "cruiser.h"

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
	void render();
	int validateFleetSize();
	Ship* chooseRandomShip(const Fleet& chosenFleet);
};