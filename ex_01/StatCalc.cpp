//
// Created by ELON HADAD on 17/11/2022.
//

#include "StatCalc.h"
#include <iostream>
#include <sstream>
#include <cstring>

StatCalc::StatCalc(int dimSize, int obSize) : dim_size(dimSize), ob_size(obSize) {
    arr_size = 20;
    dim_size = dimSize;
    ob_size = obSize;
    mean = new double[dim_size];
    str = new std::string[arr_size];
    vector = new double*[arr_size];
    for (int i = 0; i < arr_size; i++)
        vector[i] = new double[dim_size];
}

void StatCalc::resize() {
    int size ;

    if (arr_size * 2 <= ob_size)
        size = arr_size * 2;
    else
        size = ob_size;

    std::string* temp;
    double **temp2;

    temp = new std::string[size];
    temp2 = new double*[size];

    for (int i = 0; i < size; i++)
        temp2[i] = new double[dim_size];

    std::copy(str,str + count, temp);
    memcpy(temp2,vector,arr_size*sizeof (double));

    delete[]vector;
    delete[]str;
    this->str = temp;
    this->vector = temp2;
    arr_size = size;
}

void StatCalc::new_observation() {
    double d_temp;
    bool flag = false;
    std::string s_temp;
    std::stringstream s;
    std::string t_cin;

    if(count == arr_size)
        resize();

    std::cout << "Enter observation name:" << std::endl;
    std::cin >> t_cin;

    int j = 0;
    for (; j < count; j++) {
        if (t_cin == str[j]) {
            flag = true;
            break;
        }
    }

    if(!flag)
        str[count] = t_cin;

    std::cin.ignore();    // clear the cin buff
    std::cout << "Enter observation values:" << std::endl;
    getline(std::cin,s_temp);

    int space = 0;
    for (char i : s_temp) {
        if (i == ' ')
            space++;
    }
    if ((space+1) != dim_size){
        std::cerr << "Invalid observation." << std::endl;
        return;
    }

    s << s_temp;
    for (int i = 0; i < dim_size ; i++) {
        s >> d_temp;
        if (!flag)
            vector[count][i] = d_temp;
        else
            vector[j][i] = d_temp;
    }

    if (!flag)
        count++;
}

void StatCalc::print_observation() {
    int j = 0;
    bool flag = true;

    std::string ob_name;
    std::cout << "Enter observation name:" << std::endl;
    std::cin >> ob_name;

    for (; j < count; j++) {
        if (ob_name == str[j]) {
            flag = false;
            std::cout << str[j] << " = [";
            for (int i = 0; i < dim_size; i++) {
                std::cout << " " << vector[j][i];
            }
            std::cout << "]" << std::endl;
        }
    }
    if (flag) {
        std::cerr << "Invalid or nonexistent observation." << std::endl;
    }
}

void StatCalc::print_mean() {

    if(count == 0) {
        std::cerr << "Empty calculator.\n";
        return;
    }

    std::cout << "mean = [" ;
    for (int i = 0; i < dim_size; i++) {
        double sum = 0;
        for (int j = 0; j < count; j++) {
            sum += vector[j][i];
        }
        std::cout << " " << (sum/count);
        }
    std::cout << "]"<<std::endl;
}

void StatCalc::print_matrix() {

    if(count == 0) {
        std::cerr << "Empty calculator.\n";
        return;
    }

    // calc the mean for matrix calculation;

    for (int i = 0; i < dim_size; i++) {
        double sum = 0;
        for (int j = 0; j < count; j++) {
            sum += vector[j][i];
        }
        mean[i] = (sum/count);
    }

    // calc the cov matrix;
    std::cout << "cov = [" << std::endl;

    for (int k = 0; k < dim_size; k++) {
        for (int i = 0; i < dim_size; i++) {
            float temp = 0;
            for (int j = 0; j < count; j++) {
                temp += (vector[j][k] - mean[k]) * (vector[j][i] - mean[i]);
            }
            if (count > 1) {

                std::cout << " " << (temp / (count - 1));
            }
            if (count == 1){
                std::cout << " " << (temp / (count));
            }
        }
        std::cout << "\n";
    }
    std::cout << "]";
}

void StatCalc::start() {
    std::cout << "[1] New observation" << std::endl;
    std::cout << "[2] Print observation" << std::endl;
    std::cout << "[3] Expected value vector" << std::endl;
    std::cout << "[4] Covariance matrix" << std::endl;
    std::cout << "[5] Exit" << std::endl;


    while (true){
        std::string choice;
        getline(std::cin, choice);
        if (choice == "1") {
            new_observation();
        }
        else if (choice == "2") {
            print_observation();
            std::cin.ignore();
        }
        else if (choice == "3") {
            print_mean();
        }
        else if (choice == "4") {
            print_matrix();
        }
        else if (choice == "5") {
            clear();
            exit(0);
        }
        else{
            std::cerr << "Invalid option." << std::endl;
        }
    }
}

void StatCalc::clear() {
    delete[]str;
    delete[]mean;

    for (int i = 0; i < count; i++) {
        delete[]vector[i];
    }
    delete[]vector;
}
