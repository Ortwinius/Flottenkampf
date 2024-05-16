#pragma once

enum ShipType
{
	FighterType,
	DestroyerType,
	CruiserType
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
}
