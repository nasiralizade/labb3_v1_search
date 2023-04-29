//
// Created by Nasir Alizade on 2023-04-28.
//

#include "datagenerator.h"

std::vector<int> generate_primes(int limit) {
    std::vector<bool> is_prime(limit + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int p = 2; p * p <= limit; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                is_prime[i] = false;
            }
        }
    }
    std::vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

Node *build_binary_search_tree(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    if (first >= last) {
        return nullptr;
    }
    auto mid = (first + std::distance(first, last) / 2);
    Node *root = new Node(*mid);
    root->left = build_binary_search_tree(first, mid);
    root->right = build_binary_search_tree(mid + 1, last);
    return root;
}

std::vector<hash_node *> build_hashtable(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    int reserved_size = std::distance(first, last);
    std::vector<hash_node *> hashtable(reserved_size, nullptr);

    for (auto it = first; it != last; ++it) {
        insert_into_hashtable(hashtable, *it, reserved_size);
    }

    return hashtable;
}

void insert_into_hashtable(std::vector<hash_node *> &hashtable, int data, int reserved_size) {
    int hash = data % reserved_size;
    if (!hashtable[hash]) {
        hashtable[hash] = new hash_node(data);
    } else {
        auto new_node = new hash_node(data);
        new_node->next = hashtable[hash];
        hashtable[hash] = new_node;
    }
}


