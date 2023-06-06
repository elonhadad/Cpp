//
// Created by ELON HADAD on 20/01/2023.
//

#include "Management_system.h"
#include "InvalidInput.h"

using namespace std;

Management_system::Management_system() {
    this->graph = new Graph();
}

Management_system::Management_system(const Management_system &m) {
    this->graph = m.graph;
}

Management_system &Management_system::operator=(const Management_system &m) {
    if (this != &m) {
        delete graph;
        this->graph = m.graph;
    }
    return *this;
}

void Management_system::read_files(const string &file) {

    ifstream my_file(file, ios::in);

    string source, target, temp;
    int weight;

    while (my_file >> source >> target >> temp) {
        validate(source);
        graph->add_vertex(source);
        validate(target);
        graph->add_vertex(target);
        validate_integer(temp, file);
        weight = stoi(temp);
        graph->add_edge(source, target, weight);
    }
    my_file.close();
}

bool Management_system::validate(const string &str) {
    if (str.length() > 16 || str == "exit")
        throw InvalidInput("invalid source/target.");
    return true;
}

bool Management_system::validate_integer(const string &str, const string &file) {
    for (char i: str) {
        if (!isdigit(i)) {
            string ss = "ERROR: node definition in ";
            ss.append(file);
            ss.append(" is invalid\n");
            throw InvalidInput(ss);
        }
    }
    return true;
}

void Management_system::write_file(const string &str) {
    ofstream file;
    string line;
    file.open(str);
    graph->printGraph(file);
    file.close();
}

void Management_system::user_interface() {
    string user_input;

    while (true) {
        cin >> user_input;
        if (user_input == "exit")
            return;
        graph->printGraph(user_input);
        cout << endl;
    }
}
