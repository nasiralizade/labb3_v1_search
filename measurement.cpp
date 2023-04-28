//
// Created by Nasir Alizade on 2023-04-28.
//

#include "measurement.h"

double average_value(std::vector<double> &data) {
    double sum=std::accumulate(data.begin(), data.end(),0.0);
    int N=data.size();
    double avg=sum/N;
    return avg;
}

double std_dev(std::vector<double> &data) {
    int N=data.size();
    double
}
