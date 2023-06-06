//
// Created by ELON HADAD on 20/01/2023.
//

#ifndef EX_05_MANAGEMENT_SYSTEM_H
#define EX_05_MANAGEMENT_SYSTEM_H
#include "Graph.h"
#include <sstream>
#include <stdexcept>


class Management_system {

public:
    Management_system();                                                        // Constructor.
    Management_system(const Management_system& m);                              // Copy Constructor.
    Management_system& operator=(const Management_system& m);                   // Copy assignment operator.
    void read_files(const string& file);                                        // Read files & insert to graph.
    void write_file(const string& str);                                         // Write the output file.
    void user_interface();                                                      // Asking for input.
    static bool validate(const string& str);                                    // Validate names.
    static bool validate_integer(const string& str, const string& file);        // Validate third column in file is integer.
    virtual ~Management_system()=default;                                       // Destructor.

private:
    Graph* graph;
};


#endif //EX_05_MANAGEMENT_SYSTEM_H