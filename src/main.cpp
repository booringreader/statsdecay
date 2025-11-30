#include "branching_model.h"
#include "probability_util.h"
#include "stats.h"
#include "histogram.h"
#include <iostream>
#include<bits/stdc++.h>

int main() {
    RNG rng;
    BranchingModel model(3333, 1000000);  // max_gen=3333, reasonable max_particles for testing

    const int num_simulations = 100;
    std::vector<BranchingResult> results;
    Histogram hist_k(20, 0.0, 3.0);  // Histogram for k values, 20 bins from 0 to 3

    for (int i = 0; i < num_simulations; ++i) {
        auto result = model.simulate(1.0, rng);  // 1 kg Pu
        results.push_back(result);

        for (double k : result.k_values) {
            hist_k.add(k);
        }
    }

    // Compute overall stats
    Stats overall_stats = compute_stats_from_results(results);
    std::cout << "Average generations completed: " << overall_stats.mean_generations << std::endl;
    std::cout << "Average k: " << overall_stats.mean_k << std::endl;
    std::cout << "Variance of k: " << overall_stats.variance_k << std::endl;

    // Print histogram
    auto hist_bins = hist_k.get_bins();
    std::cout << "\nHistogram of k values (bins: count):" << std::endl;
    for (size_t i = 0; i < hist_bins.size(); ++i) {
        double bin_start = 0.0 + (i * 3.0 / 20.0);
        std::cout << "[" << bin_start << "-" << bin_start + (3.0 / 20.0) << "]: " << hist_bins[i] << std::endl;
    }

    return 0;
}