#pragma once

#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>
#include "ship.h"

class Game
{
public:
	Game();
	~Game();

private:
	std::vector<std::unique_ptr<Ship>> fleet1;
	std::vector<std::unique_ptr<Ship>> fleet2;
	bool gameIsRunning;

	void initGame();
	void run();
	void update();
	void handleInput();
	void render();
	int validateFleetSize();
};