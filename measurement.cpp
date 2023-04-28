//
// Created by Nasir Alizade on 2023-04-28.
//

#include "measurement.h"

double average_value(std::vector<double> &data) {
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    int N = data.size();
    double avg = sum / N;
    return avg;
}

double std_dev(std::vector<double> &data) {
    const size_t N = data.size();
    double avg_val = average_value(data);
    double dev_square = 0;

    for (double &itr: data) {
        dev_square += pow((itr - avg_val), 2);
    }
    return std::sqrt(dev_square * (1.0 / (N - 1)));
}

double time_it(bool (*search_function)(std::vector<int>::iterator, std::vector<int>::iterator, const int &),
               std::vector<int>::iterator first, std::vector<int>::iterator last, int find) {
    auto start = std::chrono::steady_clock::now();
    search_function(first, last, find);
    auto stop = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> total = (stop - start);
    return total.count();
}

Node *build_binary_search_tree(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    if (first >= last) {
        return nullptr;
    }
    auto mid = (first + std::distance(first, last) / 2);
    Node *root = new Node(*mid);
    root->left = build_binary_search_tree(first, mid - 1);
    root->right = build_binary_search_tree(mid + 1, last);
    return root;
}
