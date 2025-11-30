#include "branching_model.h"
#include<algorithm>
#include<bits/stdc++.h>

#define max_particles_allowed (6 * 1e23)
BranchingModel::BranchingModel(int max_gen, int max_particles){
    max_generations = max_gen;
    max_particles = max_particles_allowed;
}
BranchingResult BranchingModel::simulate(double mass_kg, RNG& rng){
    BranchingResult result;

    std::vector<int> current_neutrons = {1};
    int particle_count_allowed = max_particles_allowed * (((int)mass_kg*1000)/239); // 239 for plutonium    

    for(int g=1; g<max_generations; g++){
        if(current_neutrons.size() > particle_count_allowed) break;

        double p_continue = rng.uniform(0, 1);
        double p_die = rng.uniform(0, 1-p_continue);
        double p_split = 1 - (p_continue + p_die);

        std::vector<int> next_neutrons;
        for(int i=0; i<current_neutrons.size(); i++){
            double r = rng.uniform(0, 1);

            // if absorbed
            if(r < p_continue) next_neutrons.push_back(1);
            else if(r < (p_continue + p_die)) continue;
            else{
                int split = rng.randint(0, 5);
                for(int i=0; i<split; i++) next_neutrons.push_back(i);
            }
        }        
        if(current_neutrons.size() > 0){
            double k = (int)next_neutrons.size()/current_neutrons.size();
            result.k_values.push_back(k);
        }
        current_neutrons = next_neutrons;
        if(current_neutrons.empty()) break;
    }

    result.generations_completed = result.k_values.size();
    return result;
}