#include "histogram.h"
#include <algorithm>

Histogram::Histogram(int bins, double min, double max) 
    : num_bins(bins), min_val(min), bin_width((max - min) / bins) {}

void Histogram::add(double val) {
    if (val >= min_val && val < min_val + num_bins * bin_width) {
        data.push_back(val);
    }
}

std::vector<double> Histogram::get_bins() const {
    std::vector<double> counts(num_bins, 0.0);
    for (double val : data) {
        int bin_idx = static_cast<int>((val - min_val) / bin_width);
        if (bin_idx >= 0 && bin_idx < num_bins) {
            ++counts[bin_idx];
        }
    }
    return counts;
}