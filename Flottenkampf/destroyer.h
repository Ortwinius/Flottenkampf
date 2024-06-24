#pragma once

#include "ship.h"

class Destroyer : public Ship
{
public:
	Destroyer()
	{
		initialize();
	}

	~Destroyer() = default;

	void attack(Ship* other) override;

private:
	void initialize() override;
};