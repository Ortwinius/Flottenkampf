#pragma once

#include <random>

const int generateRandomNumber(std::mt19937& gen, int min, int max);

const std::string& convertShipTypeToString(int type);