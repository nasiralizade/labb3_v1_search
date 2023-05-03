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
bool hashtable_search(std::vector<hash_node*>::iterator first,std::vector<hash_node*>::iterator last,int& target);
////////////////////////////////////////////////////////




#endif //LABB3_V1_ALGORITHMS_H
