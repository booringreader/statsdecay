#include "branching_model.h"
#include <algorithm>
#include <bits/stdc++.h>
#define MAX_PARTICLES_ALLOWED (6LL * 10000000LL) // close to a mole

BranchingModel::BranchingModel(int max_gen, long long max_part) {
    max_generations = max_gen;
    max_particles = std::min(max_part, MAX_PARTICLES_ALLOWED);
}

BranchingResult BranchingModel::simulate(double mass_kg, RNG& rng) {
    BranchingResult result;
    std::vector<int> current_neutrons = {1};
    long long particle_count_allowed = MAX_PARTICLES_ALLOWED * static_cast<long long>(((int)(mass_kg * 1000)) / 239);  // Approx atoms in Pu

    for (int g = 1; g <= max_generations; ++g) {
        if (static_cast<long long>(current_neutrons.size()) > particle_count_allowed) {
            break;
        }

        double p_continue = rng.uniform(0.0, 1.0);
        double p_die = rng.uniform(0.0, 1.0 - p_continue);
        double p_split = 1.0 - (p_continue + p_die);

        std::vector<int> next_neutrons;
        for (size_t i = 0; i < current_neutrons.size(); ++i) {
            double r = rng.uniform(0.0, 1.0);
            if (r < p_continue) {
                next_neutrons.push_back(1);  // Continue (scatter)
            } else if (r < (p_continue + p_die)) {
                // Die (absorbed/leak)
                continue;
            } else {
                int split = rng.randint(0, 5);  // Offspring from fission (0-5, avg 2.5)
                for (int j = 0; j < split; ++j) {
                    next_neutrons.push_back(1);  // Fixed: push 1 per offspring neutron
                }
            }
        }

        size_t current_size = current_neutrons.size();
        if (current_size > 0) {
            double k = static_cast<double>(next_neutrons.size()) / current_size;
            result.k_values.push_back(k);
        }

        current_neutrons = std::move(next_neutrons);
        if (current_neutrons.empty()) {
            break;
        }
    }

    result.generations_completed = static_cast<int>(result.k_values.size());
    return result;
}