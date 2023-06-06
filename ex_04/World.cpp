//
// Created by ELON HADAD on 15/12/2022.
//

#include "World.h"
#include <iostream>
#define MAX_SIZE 100

using namespace std;

World::World() {
    this->pop = nullptr;
}

int* World::goal = nullptr;
Virus* World::best = nullptr;
int World::size;
int World::dim;

void World::run(string file_1, string file_2) {

    read_files(file_1, file_2);
    stringstream s;
    string str;
    int num = 0;
    getline(cin,str);

    s<<str;
    s>>num;

    while (true){
        if (num == 0 || best->getGrade() == 0) {
            pop->getQueue()->print();
            print_best();
            delete pop;
            return;
        }
        (*pop)++;
        pop->Individual_update();
        num--;
    }
}

void World::read_files(const string& file_1, string file_2) {

    fstream my_file;
    my_file.open(file_1, ios::in);
    fstream my_file_2;
    my_file_2.open(file_2, ios::in);

    // FILE 1
    if (!my_file)
        cerr << "No such file.";

    string ch;
    stringstream s;

    getline(my_file,ch);
    dim = stoi(ch);

    s.clear();
    getline(my_file,ch);
    s<<ch;

    int cnt =0;

    goal = new int[MAX_SIZE];
    while(!s.eof()) {
        s >> goal[cnt];
        cnt++;
    }
    if (cnt != dim) {
        cerr << "Invalid input.\n";
        exit(0);
    }
    my_file.close();

    // FILE 2
    if (!my_file_2)
        cerr << "No such file.";

    string line;
    string num;

    getline(my_file_2,num);
    size = stoi(num);
    string virus_name;
    string temp_name;
    int vec[dim];

    pop = new Population();

    while (getline(my_file_2, line)) {
        virus_name ="";
        stringstream input(line);
        int count = 0;

        input >> temp_name;
        virus_name += temp_name + " ";
        input>> temp_name;
        virus_name += temp_name;

        while(!input.eof()) {
            input >> vec[count];
            count++;
        }
        if (count != dim) {
            cerr << "Invalid input.\n";
            exit(0);
        }

        if (virus_name[0] == 'P') {
            Papilloma *v = new Papilloma(virus_name, vec);
            v->setGrade();
            pop->getQueue()->enqueueSorted(*v);
        }
        else if (virus_name[0] == 'L') {
            Lentivirus *v = new Lentivirus(virus_name, vec);
            v->setGrade();
            pop->getQueue()->enqueueSorted(*v);
        }
        else if (virus_name[0] == 'M'){
            Mimivirus *v = new Mimivirus(virus_name, vec);
            v->setGrade();
            pop->getQueue()->enqueueSorted(*v);
        }
    }
    best = new Virus(pop->getQueue()->getTail()->getData());
    my_file_2.close();
}

void World::print_best() {
    if (best->getRealVer() == 0)
        cout<<"\n"<<best->getName()<<" ";
    else
        cout<<"\n"<<best->getName()<<"_"<<best->getRealVer()<<" ";
    best->print_vector();
    cout<<"\n";

}
