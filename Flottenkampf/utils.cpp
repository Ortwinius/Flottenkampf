#include "utils.h"

const int generateRandomNumber(std::mt19937& gen, int min, int max)
{
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(gen);
}

std::string convertShipTypeToString(int type)
{
	switch (type)
	{
	case 0:
		return "Fighter";
	case 1:
		return "Destroyer";
	case 2:
		return "Cruiser";
	default:
		return "Uninitialized";
	}
}
