#pragma once

#include <random>

const int generateRandomNumber(std::mt19937& gen, int min, int max);

std::string convertShipTypeToString(int type);