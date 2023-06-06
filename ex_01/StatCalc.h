//
// Created by ELON HADAD on 17/11/2022.
//

#ifndef EX01_STATCALC_H
#define EX01_STATCALC_H
#include <string>

class StatCalc {

public:
    // constructor
    StatCalc(int dimSize, int obSize);
    // operations menu.
    void start();
    // entering a new observation to the calculator.
    void new_observation();
    // print an observation vector from the calculator.
    void print_observation();
    // printing the mean vector for the observations in the calculator.
    void print_mean();
    // calculating the mean vector of the calculator and printing the covariance matrix.
    void print_matrix();
    // changing the size of the max observations in th calculator.
    void resize();
    // delete all dynamic allocation.
    void clear();

private:
    int count = 0;
    int dim_size;
    int ob_size;
    double **vector;
    std::string *str;
    double *mean;
    int arr_size;
};

#endif //EX01_STATCALC_H
