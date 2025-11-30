#ifndef PROBABILITY_UTIL_H
#define PROBABILITY_UTIL_H

#include <random>

class RNG {
private:
    std::mt19937 gen;

public:
    RNG();
    double uniform(double min, double max);
    int randint(int min, int max);
};

#endif