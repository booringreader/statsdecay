#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <vector>

class Histogram {
private:
    std::vector<double> data;
    int num_bins;
    double min_val, bin_width;

public:
    Histogram(int bins, double min, double max);
    void add(double val);
    std::vector<double> get_bins() const;  // Returns vector of bin counts
};

#endif // HISTOGRAM_H