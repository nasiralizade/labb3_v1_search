#include <iostream>
#include <fstream>
#include "datagenerator.h"
#include "algorithms.h"
#include "measurement.h"
#include "node.h"

#define RED "\033[91m"
#define GREEN "\033[92m"
#define YELLOW "\033[93m"
#define BLUE "\033[94m"
#define END "\033[0m"
#define COUNT 10
const auto SIZE = 5000000;
const auto REPETITIONS = 10;
const auto SAMPLES = 20;

void menu();

void delete_files();


void run_search(int choice, int SIZE, int REPETITIONS, int SAMPLES);

std::vector<hash_node *> build_hashtable(auto anAuto, auto anAuto1);

int main() {
    srand(time(nullptr));
    menu();

    // Print functions
    //printHash(hash_table);*/
    //print2DUtil(tree, 0);

    return 0;
}

void menu() {
    std::string line(40, '-');
    std::cout << line << "\n";
    int choice;
    while (true) {
        std::cout << GREEN "SEARCH ALGORITHMS MENU\n" << END;
        std::cout <<BLUE <<line <<END "\n";
        std::cout << "\t1. linear search\n";
        std::cout << "\t2. binary search\n";
        std::cout << "\t3. binary search tree\n";
        std::cout << "\t4. hashtable search \n";
        std::cout << "\t5. delete files\n";
        std::cout << "\t6. exit\n\n";
        std::cout << "Enter an option (1-6): ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << RED "Invalid input. Please enter a number.\n" << END;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (choice < 1 || choice > 6) {
            std::cerr << RED "Invalid choice. Please enter a number between 1 and 7.\n" << END;
        } else if (choice == 5) {
            delete_files();
        } else if (choice == 6) {
            break;
        } else {
            std::cout << line << "\n";
            run_search(choice, SIZE, REPETITIONS, SAMPLES);
        }
        std::cout << "\n";
    }

}

void run_search(int choice, int SIZE, int REPETITIONS, int SAMPLES) {
    std::vector<int> data;
    std::vector<double> period(SAMPLES);

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
            hash_table = build_hashtable(data.begin(), data.end());
            tree = build_binary_search_tree(data.begin(), data.end());
            for (int i = 0; i < SAMPLES; i++) {
                // number to find for each iteration
                int number_to_find = data[rand() % data.size()];

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
                    //period[i] = time_it(&search_hashtable, hash_table.begin(), hash_table.end(), number_to_find);
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
    std::string filename[] = {"binary_search_tree.txt", "binary_search.txt", "hash_table.txt", "sequential_search.txt"};
    for (const auto &file: filename) {
        if (remove(file.c_str()) != 0) {
            std::cerr << RED "Error removing file " END << file << std::endl;
        } else {
            std::cout << "File " << file << GREEN " removed successfully." END << std::endl;
        }
    }
}



