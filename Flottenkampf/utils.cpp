#include "utils.h"

const int generateRandomNumber(std::mt19937& gen, int min, int max)
{
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(gen);
}

const std::string& convertShipTypeToString(int type)
{
	switch (type)
	{
	case 1:
		return "Fighter";
	case 2:
		return "Destroyer";
	case 3:
		return "Cruiser";
	default:
		return "";
	}
}
