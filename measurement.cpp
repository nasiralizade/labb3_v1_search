//
// Created by Nasir Alizade on 2023-04-28.
//

#include <iostream>
#include "measurement.h"

double average_value(std::vector<double> &data) {
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return (sum/(data.size()));
}

double std_dev(std::vector<double> &data) {
    const size_t N = data.size();
    double avg_val = average_value(data);
    double dev_square = 0.0;
    for (const double &itr: data) {
        dev_square += pow((itr - avg_val), 2);
    }
    return std::sqrt(dev_square / (N - 1));
}

double time_it(bool (*search_function)(std::vector<int>::iterator, std::vector<int>::iterator, const int &),
               std::vector<int>::iterator first, std::vector<int>::iterator last, int find) {
    auto start = std::chrono::steady_clock::now();
    auto found = search_function(first, last, find);
    auto stop = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> total = (stop - start);
    if (!found) { std::cout << "NOT FOUND: " << find << "\n"; }
    return total.count();
}


double time_it(bool (*search)(Node *, int &), Node *root, int &find) {
    auto start = std::chrono::steady_clock::now();
    auto found = search(root, find);
    auto stop = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> total = (stop - start);
    if (!found) { std::cout << "NOT FOUND: " << find << "\n"; }
    return total.count();
}

double time_it(bool (*search)(std::vector<hash_node *>::iterator, std::vector<hash_node *>::iterator,  int &),
               std::vector<hash_node *>::iterator first, std::vector<hash_node *>::iterator last, int &number) {
    auto start = std::chrono::steady_clock::now();
    auto found=search(first, last, number);
    auto stop = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> total = (stop - start);
    if (!found) { std::cout << "NOT FOUND: " << number << "\n"; }
    return total.count();
}





