#include<bits/stdc++.h>
#include<chrono>
#include "probability_util.h"
#include "branching_model.h"
#include "histogram.h"

int main(void){
    int max_generations, bins=10;
    double mass_kg;
    std::cin >> mass_kg >> max_generations;
    
    unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    RNG rng(seed);

    BranchingModel model(max_generations, 500);
    auto result =  model.simulate(mass_kg, rng);

    std::cout << "\nSimulated " << result.generations_completed << " generations.\n";

    print_histogram(result.k_values, bins);
    return 0;
}