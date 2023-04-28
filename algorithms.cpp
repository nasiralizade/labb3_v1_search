//
// Created by Nasir Alizade on 2023-04-28.
//

#include "algorithms.h"

bool linear_search(std::vector<int>::iterator first, std::vector<int>::iterator last, const int &target) {
    for (auto i = first; first != last; i++) {
        if (*i == target) {
            return true;
        }
        return false;
    }
}
