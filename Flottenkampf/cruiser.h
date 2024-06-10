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

	void attack(Ship& other) override
	{
		ShipType type = other.getShipType();

		if (type == ShipType::Uninitialized)
		{
			std::cerr << "Error: Target ship has an unknown type." << std::endl;
			return; // Handle the error appropriately
		}

		std::cout << "Bombarding ship of type " << convertShipTypeToString(other.getShipType()) << std::endl;
	}
private:
	void initialize()
	{
		this->hullHP = 250;
		this->size = 8;
		this->damage = 50;
		this->ability = Ability::Bombarding;
		this->type = ShipType::CruiserType;

		std::cout << "Cruiser initialized" << std::endl;
	}
};