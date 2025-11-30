#pragma once
#include<vector>
#include<cstdint>
#include "probability_util.h"

struct BranchingResult{
    std::vector<double> k_values;
    int generations_completed;
};

class BranchingModel{
public:
    int max_generations;
    int max_particles_allowed;

    BranchingModel(int max_gen, int max_particles);
    BranchingResult simulate(double mass_kg, RNG& rng);
};