# Branching Simulation

A modular C++ simulation of a neutron branching process for modeling fission chain reactions (e.g., in plutonium bombs). The model uses a Galton-Watson branching process with stochastic probabilities per generation.

## Structure
- `src/`: Source files.
  - `main.cpp`: Entry point; runs multiple simulations, computes stats, and prints a simple histogram of k-values.
  - `branching_model.h/.cpp`: Core model class and simulation logic.
  - `probability_utils.h/.cpp`: RNG class for uniform and integer random sampling.
  - `stats.h/.cpp`: Statistics computation (mean/variance of k and generations).
  - `histogram.h/.cpp`: Simple histogram for k-value distribution.
- `Makefile`: Builds the project (`make` to compile, `make clean` to clean).
- `README.md`: This file.

## Building and Running
1. Ensure C++11-compatible compiler (e.g., g++).
2. Run `make` in the root directory.
3. Execute `./branching_sim` to run 100 simulations for 1 kg Pu, printing averages and histogram.

## Notes
- Probabilities are redrawn each generation (time-inhomogeneous Markov chain).
- Fixed bug in fission offspring pushing (now pushes `1` per split neutron).
- For large `max_generations` (e.g., 3333), simulations may terminate early due to extinction or particle limits.
- Extend `main.cpp` for more runs or output (e.g., to file for plotting).
- Limitations: No spatial leakage, fixed ν distribution; see physics lit for realism.
