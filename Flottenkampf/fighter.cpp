#include "fighter.h"

void Fighter::initialize()
{
	this->type = ShipType::CruiserType;
	this->hullHP = 75;
	this->size = 4;
	this->attackDamage = 60;
	this->ability = Ability::CriticalHit;

	std::cout << "Fighter initialized" << std::endl;
}

void Fighter::attack(Ship* other)
{
	ShipType type = other->getShipType();

	if (type == ShipType::Uninitialized)
	{
		std::cerr << "Error: Target ship has an unknown type." << std::endl;
		return;
	}

	int attackProb = other->getSize();
	std::cout << "attackProb: " << attackProb << std::endl;
	int diceNumber = rand() % 10; 

	if (diceNumber >= attackProb) // not succesful 
	{
		std::cout << "Attack not successful - next turn..." << std::endl;
		return;
	}

	// deal damage
	std::cout << "Figher hits ship of type " << convertShipTypeToString(other->getShipType()) << " with critical effect" << std::endl;

	// double damage if dice >= 9
	int damageToDeal = diceNumber >= 9 ? this->attackDamage * 2 : this->attackDamage;

	other->takeDamage(damageToDeal);

	std::cout << convertShipTypeToString(other->getShipType())
		<< " took damage, new HP: " << other->getHullHP() << std::endl;


}