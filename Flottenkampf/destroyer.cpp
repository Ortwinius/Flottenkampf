#include "destroyer.h"

void Destroyer::initialize()
{
	this->type = ShipType::DestroyerType;
	this->hullHP = 150;
	this->size = 6;
	this->attackDamage = 60;
	this->ability = Ability::TargetSeeking;

	std::cout << "Destroyer initialized" << std::endl;
}

void Destroyer::attack(Ship* other)
{
	ShipType type = other->getShipType();

	if (type == ShipType::Uninitialized)
	{
		std::cerr << "Error: Target ship has an unknown type." << std::endl;
		return; 
	}

	int attackProb = other->getSize();
	std::cout << "attackProb: " << attackProb << std::endl;
	int diceNumber = rand() % 8; // Trefferproben sind um 2 erleichtert: 10 - 2

	if (diceNumber >= attackProb) // not succesful 
	{ 
		std::cout << "Attack not successful - next turn..." << std::endl;
		return;
	}

	// deal damage
	std::cout << "Destroyer targetseeks ship of type " << convertShipTypeToString(other->getShipType()) << std::endl;
	other->takeDamage(this->attackDamage);

	std::cout << convertShipTypeToString(other->getShipType())
		<< " took damage, new HP: " << other->getHullHP() << std::endl;

	
}
