//
// Created by Nasir Alizade on 2023-04-24.
//

#ifndef LABB3_V1_ALGORITHMS_H
#define LABB3_V1_ALGORITHMS_H

#include <vector>
#include "node.h"

bool linear_search(std::vector<int>::iterator first, std::vector<int>::iterator last, const int &target);
bool binary_search(std::vector<int>::iterator first, std::vector<int>::iterator last, const int &target);
bool binary_search_tree(Node*root, int &target);
bool search_hashtable(std::vector<std::unique_ptr<hash_node>>&hashtable,int data, int reserved_size);

#endif //LABB3_V1_ALGORITHMS_H
