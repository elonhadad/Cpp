#include <iostream>
#include "StatCalc.h"

int main(int argc, char *argv[]) {
    if (argc != 3){
        std::cerr << "invalid arguments <int> <int>. \n";
        exit(-1);
    }
    StatCalc* stat;

    stat = new StatCalc(std::stoi(argv[1]), std::stoi(argv[2]));
    stat->start();

    return 0;
}
