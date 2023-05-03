//
// Created by Nasir Alizade on 2023-04-28.
//

#include <iostream>
#include "algorithms.h"

bool linear_search(std::vector<int>::iterator first, std::vector<int>::iterator last, const int &target) {
    for (auto i = first; i != last; i++) {
        if (*i == target) {
            return true;
        }
    }
    return false;
}

bool binary_search(std::vector<int>::iterator first, std::vector<int>::iterator last, const int &target) {
    while (first <= last) {
        auto mid = first + (last - first) / 2;
        if (*mid == target) {
            return true;
        }
        if (*mid < target) {
            first = mid + 1;
        } else {
            last = mid - 1;
        }
    }
    return false;
}
bool binary_search_tree(Node *root, int &target) {
    if (!root){
        return false;
    }
    while (root) {
        if (root->data == target) {
            return true;
        } else if (target < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return false;
}


bool hashtable_search(std::vector<hash_node *>::iterator first, std::vector<hash_node *>::iterator last, int &target) {
    hash_node* node_index=*(first+(target % std::distance(first, last)));
    while (node_index!= nullptr){
        if (node_index->data == target){
            return true;
        }node_index=node_index->next;
    }
    return false;
}
