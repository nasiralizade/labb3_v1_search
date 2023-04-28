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
