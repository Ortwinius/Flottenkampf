#include "cruiser.h"

void Cruiser::initialize()
{
	this->type = ShipType::CruiserType;
	this->hullHP = 250;
	this->size = 8;
	this->attackDamage = 50;
	this->ability = Ability::Bombarding;

	std::cout << "Cruiser initialized" << std::endl;
}

void Cruiser::attack(Ship* other)
{
	ShipType type = other->getShipType();

	if (type == ShipType::Uninitialized)
	{
		std::cerr << "Error: Target ship has an unknown type." << std::endl;
		return; // Handle the error appropriately
	}
	
	// cruiser attacks until attack is unsuccessful
	while (true)
	{
		if (other->getHullHP() < 1) // ship already destroyed
		{
			std::cout << "DEBUG: Ship already destroyed. Skipping" << std::endl;
			return;
		}

		int attackProb = other->getSize();
		std::cout << "attackProb: " << attackProb << std::endl;
		int diceNumber = (rand() % 10) + 1;
		std::cout << "dice: " << diceNumber << std::endl;

		if (diceNumber < attackProb) // not succesful
		{
			std::cout << "Attack not successful - next turn..." << std::endl;
			return;
		}

		// deal damage
		std::cout << "Cruiser bombards ship of type: " << convertShipTypeToString(other->getShipType()) << std::endl;

		other->takeDamage(this->attackDamage);

		std::cout << convertShipTypeToString(other->getShipType())
			<< " took damage, new HP: " << other->getHullHP() << std::endl;
	}
}
