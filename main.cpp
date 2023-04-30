#include <iostream>
#include "run_search.h"
#define RED "\033[91m"
#define GREEN "\033[92m"
#define YELLOW "\033[93m"
#define BLUE "\033[94m"
#define END "\033[0m"
#define COUNT 10
const auto SIZE = 1000000;
const auto REPETITIONS = 20;
const auto SAMPLES = 10000;

void menu();



int main() {
    srand(time(nullptr));
    std::vector<int>test{2,4,1,4,7,3,146,23,1,5};

    menu();



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








