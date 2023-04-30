//
// Created by Nasir Alizade on 2023-04-28.
//

#include <fstream>
#include <iostream>
#include "datagenerator.h"

std::vector<int> generate_primes(int limit) {
    // Delete old primes.txt file
    std::remove("primes.txt");
    assert(limit >= 2);
    // Initialize a boolean vector to track whether each number is prime
    std::vector<bool> is_prime(limit + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;

    // Use the Sieve of Eratosthenes algorithm to mark non-prime numbers
    for (int p = 2; p * p <= limit; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                is_prime[i] = false;
            }
        }
    }

    // Create a vector of prime numbers from the boolean vector
    std::vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    // Write primes to file
    std::ofstream outfile("primes.txt");
    if (outfile.is_open()) {
        for (int prime : primes) {
            outfile << prime << '\n';
        }
        outfile.close();
    } else {
        std::cerr << "Error: failed to open primes.txt for writing\n";
    }
    return primes;
}

Node *build_binary_search_tree(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    if (first >= last) {
        return nullptr;
    }
    auto mid = std::next(first, std::distance(first, last) / 2);
    Node *root = new Node(*mid);
    root->left = build_binary_search_tree(first, mid);
    root->right = build_binary_search_tree(mid + 1, last);
    return root;
}

std::vector<hash_node *> build_hashtable(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    std::size_t reserved_size = std::distance(first, last);
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

std::vector<int> generate_random(int limit) {

    std::vector<int>data;
    for (int i = 0; i < limit; ++i) {
        data.push_back(rand());
    }std::sort(data.begin(), data.end());
    return data;
}

std::vector<int> read_data_from_file(const std::string &filename) {
    std::vector<int> data;
    std::ifstream infile(filename);
    if (infile.is_open()) {
        int value;
        while (infile >> value) {
            data.push_back(value);
        }
        infile.close();
    } else {
        std::cerr << "Error: failed to open file " << filename << " for reading\n";
    }
    return data;
}




