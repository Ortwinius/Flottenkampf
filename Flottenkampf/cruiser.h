#pragma once

#include "ship.h"

class Cruiser : public Ship
{
public:
	Cruiser() 
	{
		initialize();
	}
	
	void attack(Ship& other) override
	{
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