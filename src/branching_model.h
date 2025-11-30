#ifndef BRANCHING_MODEL_H
#define BRANCHING_MODEL_H

#include "probability_util.h"
#include<bits/stdc++.h>

struct BranchingResult {
    std::vector<double> k_values;
    int generations_completed;
};

class BranchingModel {
private:
    int max_generations;
    long long max_particles;

public:
    BranchingModel(int max_gen, long long max_part);
    BranchingResult simulate(double mass_kg, RNG& rng);
};

#endif