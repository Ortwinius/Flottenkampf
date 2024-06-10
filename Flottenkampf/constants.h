#pragma once

enum ShipType
{
	FighterType,
	DestroyerType,
	CruiserType,
	Uninitialized
};

enum Ability
{
	CriticalHit,
	TargetSeeking,
	Bombarding
};

namespace DefaultValues
{
	constexpr int minFleetShipCount = 1;
	constexpr int maxFleetShipCount = 9;
	constexpr int fleetNumber = 2;
}
