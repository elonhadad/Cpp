#include <iostream>
#include "Management_system.h"


using namespace std;

class FileNotFound : public invalid_argument {
public:
    explicit FileNotFound(const string &str) : invalid_argument(str) {};
};

bool is_file_exist(const char *fileName) {
    ifstream infile(fileName);
    return infile.good();
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: missing file!" << endl;
        exit(-1);
    }

    Management_system *city;
    city = new Management_system();

    string out = "Output.dat";
    int i = 1;
    while (argv[i]) {
        if ((is_file_exist(argv[i]) == 0) && (i == argc - 1)) {
            out = argv[i];
            break;
        }
        if (is_file_exist(argv[i]) == 0) {
            string s = "ERROR: ";
            s.append(argv[i]);
            s.append(" does not exist or cannot be opened\n");
            throw FileNotFound(s);
        }
        city->read_files(argv[i]);
        i++;
    }
    city->write_file(out);
    city->user_interface();
    delete city;

    return 0;
}
