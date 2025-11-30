#pragma once
#include <vector>
#include <string>

void print_histogram(const std::vector<double>& data, int bins);
void write_csv(const std::vector<double>& data, const std::string& filename);