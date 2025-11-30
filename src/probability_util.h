#pragma once
#include<random>

struct RNG{
    std::mt19937 gen;

    RNG(unsigned seed) : gen(seed) {};

    double uniform(double a, double b){
        std::uniform_real_distribution<double> d(a, b);
        return d(gen);
    }
    int randint(int a, int b){
        std::uniform_int_distribution<int> i(a,b);
        return i(gen);
    }
};