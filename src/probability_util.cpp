#include "probability_util.h"

RNG::RNG() : gen(std::random_device{}()) {}

double RNG::uniform(double min, double max) {
    std::uniform_real_distribution<double> dis(min, max);
    return dis(gen);
}

int RNG::randint(int min, int max) {
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}