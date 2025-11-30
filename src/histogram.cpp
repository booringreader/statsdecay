#include<iostream>
#include<iomanip>
#include "histogram.h"
#include "branching_model.h"
#include<fstream>

void print_histogram(const std::vector<double>& data, const int bins){
    if(data.empty()) return;

    double min_value = *std::min_element(data.begin(), data.end());
    double max_value = *std::max_element(data.begin(), data.end());

    std::vector<int> counts(bins, 0);
    double bin_size = (max_value - min_value) / bins;

    for (double value : data) {
        int idx = (int)((value - min_value) / bin_size);
        if (idx == bins) idx--;
        counts[idx]++;
    }

    std::cout << "\n=== Histogram (k values) ===\n";
    for (int i = 0; i < bins; i++) {
        double bin_start = min_value + i * bin_size;
        double bin_end = bin_start + bin_size;

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "[" << bin_start << ", " << bin_end << "]: ";

        int stars = counts[i] / (data.size() / 80.0 + 1);
        for (int s = 0; s < stars; s++) std::cout << "*";
        std::cout << "\n";
    }
}

void write_csv(const std::vector<double>& data, const std::string& filename){
    std::ofstream f(filename);
    f << "k_value\n";
    for(double value : data) f << value << "\n";
    f.close();
}