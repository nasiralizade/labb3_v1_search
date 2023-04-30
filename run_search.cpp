//
// Created by Nasir Alizade on 2023-04-29.
//
#include <random>
#include "algorithms.h"
#include "run_search.h"

void run_search(int choice, int SIZE, int REPETITIONS, int SAMPLES) {
    std::vector<int> data; //data to search in
    std::vector<double> period(SAMPLES); //saves time to then calc avg

    std::vector<hash_node *> hash_table;
    Node *tree = nullptr;

    std::string filename[] = {"linear_search.txt", "binary_search.txt", "binary_search_tree.txt", "hash_table.txt"};
    std::string search_alg[] = {"linear_search", "binary_search", "binary_search_tree", "hash_table"};

    std::ofstream os;
    os.open(filename[choice - 1], std::ios::out | std::ios::app);

    if (os.is_open()) {
        std::cout << "running " << search_alg[choice - 1] << "...\n";
        os << "N\t" << "T[µs]\t" << "dev[µs]\t" << "Samples\n";
        std::cout << "N\t" << "T[µs]\t" << "dev[µs]\t" << "Samples\n";
        for (int iter = 1; iter <= REPETITIONS; iter++) {
            data = generate_primes(SIZE * iter);
            //data= read_data_from_file()
            //std::sort(data.begin(), data.end());
            //data = generate_random(SIZE * iter);
            hash_table = build_hashtable(data.begin(), data.end());
            tree = build_binary_search_tree(data.begin(), data.end());

            for (int i = 0; i < SAMPLES; i++) {
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, data.size() - 1);
                // number to find for each iteration
                int number_to_find = data[dis(gen)];
                //int number_to_find =data[distribution(generator)];
                // run it
                if (choice == 1) {
                    period[i] = time_it(&linear_search, data.begin(), data.end(), number_to_find);
                }
                if (choice == 2) {
                    period[i] = time_it(&binary_search, data.begin(), data.end(), number_to_find);
                }
                if (choice == 3) {
                    period[i] = time_it(&binary_search_tree, tree, number_to_find);
                }
                if (choice == 4) {
                    period[i] = time_it(&hashtable_search, hash_table.begin(), hash_table.end(), number_to_find);
                }
            }

            os << SIZE * iter << "\t" << average_value(period) << "\t" << std_dev(period) << "\t" << SAMPLES << '\n';
            std::cout << SIZE * iter << "\t" << average_value(period) << "\t" << std_dev(period) << "\t" << SAMPLES
                      << '\n';
        }
        os.close();
    }
}


/**
 * deleting files if they exist.
 */
void delete_files() {
    std::string filename[] = {"linear_search.txt", "binary_search.txt", "binary_search_tree.txt", "hash_table.txt"};
    for (const auto &file: filename) {
        if (remove(file.c_str()) != 0) {
            std::cerr << RED "Error removing file " END << file << std::endl;
        } else {
            std::cout << "File " << file << GREEN " removed successfully." END << std::endl;
        }
    }
}
