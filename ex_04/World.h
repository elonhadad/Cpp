//
// Created by ELON HADAD on 15/12/2022.
//

#ifndef EX_04_WORLD_H
#define EX_04_WORLD_H
#include "Population.h"
#include "Virus.h"
#include "Papilloma.h"
#include "Lentivirus.h"
#include "Mimivirus.h"
#include <fstream>
#include <sstream>

using namespace std;

class World {
public:
    World();

    /**
     * call to read_files function for reading the files,
     * manage generational transitions.
     * waiting for user input with max number of transitions.
     * @param file_1 - program argument (argv[1]).
     * @param file_2 - program argument (argv[2]).
     */
    void run(string file_1, string file_2);

    /**
     *  validate files and insert the the new virus to new population.
      * @param file_1 - first row: dimension of virus;
     *                  second row: target virus;
     * @param file_2 - first row: size of population;
     *                 other rows: every line contains name and vector for virus;
     */
    void read_files(const string& file_1, string file_2);

    /**
    * printing the all time best virus.
    */
    static void print_best();

    static int* goal;
    static int size;
    static int dim;
    static Virus* best;

private:
    Population* pop;

};

#endif //EX_04_WORLD_H