//
// Created by Nasir Alizade on 2023-04-28.
//

#ifndef LABB3_V1_MEASUREMENT_H
#define LABB3_V1_MEASUREMENT_H

#include <vector>
#include <numeric>
#include <cmath>
#include <chrono>
#include "node.h"

double time_it(bool (*search_function)(std::vector<int>::iterator, std::vector<int>::iterator, const int &),
               std::vector<int>::iterator first, std::vector<int>::iterator last, int find);

double time_it(bool (*search)(Node *, int &), Node *root, int &find);

double time_it(bool(*search)(std::vector<hash_node *>::iterator, std::vector<hash_node *>::iterator, const int &),
                std::vector<hash_node *>::iterator first, std::vector<hash_node *>::iterator last,  int &number);

double average_value(std::vector<double> &data);

double std_dev(std::vector<double> &data);

#endif //LABB3_V1_MEASUREMENT_H
