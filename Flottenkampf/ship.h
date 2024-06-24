#pragma once

#include <iostream>
#include "common.h"

// Ship interface with attack function to be implemented by child classes
class Ship
{
public:
	Ship() {}
	virtual ~Ship() = default;

	virtual void attack(Ship* other) = 0;

	int getHullHP() { return this->hullHP; }
	int getSize() { return this->size; }
	int getAttackDamage() { return this->attackDamage; }
	const ShipType& getShipType() const { return type; }
	const Ability& getAbility() const { return ability; }

protected:
	virtual void initialize() = 0;
	void takeDamage(int damage) { hullHP -= damage; }

	int hullHP;
	int size;
	int attackDamage;
	ShipType type;
	Ability ability;
};