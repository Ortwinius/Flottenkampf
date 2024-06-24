#pragma once

#include "ship.h"

class Fighter : public Ship
{
public:
	Fighter()
	{
		initialize();
	}

	~Fighter() = default;

	void attack(Ship* other) override;

private:
	void initialize() override;
};