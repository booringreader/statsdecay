#include "stats.h"
#include <numeric>
#include <cmath>

Stats compute_stats_from_results(std::vector<BranchingResult>& results) {
    Stats stats = {0.0, 0.0, 0.0};

    if (results.empty()) {
        return stats;
    }

    // Collect all k values
    std::vector<double> all_k_values;
    double sum_generations = 0.0;
    for (const auto& res : results) {
        sum_generations += res.generations_completed;
        all_k_values.insert(all_k_values.end(), res.k_values.begin(), res.k_values.end());
    }

    stats.mean_generations = sum_generations / results.size();

    if (all_k_values.empty()) {
        return stats;
    }

    double sum_k = std::accumulate(all_k_values.begin(), all_k_values.end(), 0.0);
    stats.mean_k = sum_k / all_k_values.size();

    double sum_sq_diff = 0.0;
    for (double k : all_k_values) {
        double diff = k - stats.mean_k;
        sum_sq_diff += diff * diff;
    }
    stats.variance_k = sum_sq_diff / all_k_values.size();

    return stats;
}