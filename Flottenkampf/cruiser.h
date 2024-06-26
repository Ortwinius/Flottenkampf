#pragma once

#include "ship.h"

class Cruiser : public Ship
{
public:
	Cruiser() 
	{
		initialize();
	}

	~Cruiser() = default;

	void attack(Ship* other) override;

private:
	void initialize() override;
};