//
// Created by Nasir Alizade on 2023-04-28.
//

#include "algorithms.h"

bool linear_search(std::vector<int>::iterator first, std::vector<int>::iterator last, const int &target) {
    for (auto i = first; first != last; i++) {
        if (*i == target) {
            return true;
        }
    }
    return false;
}

bool binary_search(std::vector<int>::iterator first, std::vector<int>::iterator last, const int &target) {
    while (first <= last) {
        auto mid = first + std::distance(first, last) / 2;
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

bool search_hashtable(std::vector<std::unique_ptr<hash_node>> &hashtable, int data, int reserved_size) {
    int hash = data % reserved_size;
    auto &item = hashtable[hash];
    auto current = item.get();
    while (current) {
        if (current->data == data) {
            return true;
        }
        current = current->next;

    }
    return false;
}
