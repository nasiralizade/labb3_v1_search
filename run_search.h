//
// Created by Nasir Alizade on 2023-04-29.
//

#ifndef LABB3_V1_RUN_SEARCH_H
#define LABB3_V1_RUN_SEARCH_H
#include <fstream>
#include <iostream>
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

void run_search(int choice, int SIZE, int REPETITIONS, int SAMPLES);
void delete_files();
#endif //LABB3_V1_RUN_SEARCH_H
