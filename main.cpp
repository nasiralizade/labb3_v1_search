#include <iostream>
#include <fstream>
#include "datagenerator.h"
#include "algorithms.h"
#include "measurement.h"
#include "node.h"
#define COUNT 10
const int DATA_SIZE = 200000;
const int REPETITIONS = 10;
const int SAMPLES = 10;


bool binary_search(std::vector<int>::iterator, std::vector<int>::iterator, const int &);

int main() {
    std::vector<int> data;
    std::vector<double> period(SAMPLES);

    std::vector<hash_node*> hash_table;
    Node* tree = nullptr;
    srand(time(nullptr));
    // Prime number generator
    // 2 3 5 7 11 => N = 5
    //auto vec = GetPrimeVector(5);

    std::string filename[] = { "binary_search_tree.txt", "binary_search.txt", "hash_table.txt", "sequential_search.txt" };

    data = generate_primes(DATA_SIZE * REPETITIONS);
    //hash_table = CreateHashTable(data.begin(), data.end());
    tree = build_binary_search_tree(data.begin(), data.end());



    std::ofstream os;
    os.open(filename[3], std::ios::out | std::ios::app);

    if (os.is_open())
    {
        os << "N\t" << "T[ms]\t" << "dev[ms]\t" << "Samples\n";
        for (int iter = 1; iter <= REPETITIONS; iter++)
        {
            for (int i = 0; i < SAMPLES; i++)
            {
                // number to find for each iteration
                int number_to_find = data[rand() % DATA_SIZE];

                // run it
                //period[i] = time_it(&linear_search, data.begin(), data.end(), number_to_find);
                //period[i] = time_it(&binary_search, data.begin(), data.end(), number_to_find);
                period[i] = time_it(&binary_search_tree, tree, number_to_find);
                //period[i] = time_it(&hash_table_search, hash_table.begin(), hash_table.end(), number_to_find);
            }
            os << DATA_SIZE * iter << "\t" << average_value(period) << "\t" << std_dev(period) << "\t" << SAMPLES << '\n';
            std::cout << DATA_SIZE * iter << "\t" << average_value(period) << "\t" << std_dev(period) << "\t" << SAMPLES << '\n';
        }
        os.close();
    }

    // Print functions
    //printHash(hash_table);*/
    //print2DUtil(tree, 0);

    return 0;
}



