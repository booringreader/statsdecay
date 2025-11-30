#ifndef STATS_H
#define STATS_H

#include <vector>
#include "branching_model.h"

struct Stats {
    double mean_k;
    double variance_k;
    double mean_generations;
};

Stats compute_stats_from_results(std::vector<BranchingResult>& results);

#endif // STATS_H