//
// Created by Nasir Alizade on 2023-04-24.
//

#ifndef LABB3_V1_DATAGENERATOR_H
#define LABB3_V1_DATAGENERATOR_H

#include <vector>
#include "node.h"

std::vector<int> generate_primes(int limit);
Node* build_binary_search_tree(std::vector<int>::iterator first,std::vector<int>::iterator last);


std::vector<hash_node *> build_hashtable(std::vector<int>::iterator first,std::vector<int>::iterator last);

void insert_into_hashtable(std::vector<hash_node*>& hashtable, int data, int reserved_size);
std::vector<int>generate_random(int limit);
std::vector<int> read_data_from_file(const std::string& filename);
#endif //LABB3_V1_DATAGENERATOR_H
