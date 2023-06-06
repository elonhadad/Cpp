#include <iostream>
#include "World.h"

using namespace std;
#include "Virus.h"

int main(int argc, char* argv[]) {

    if(argc != 3){
        cerr << "Usage: run the program with <init file name> <location file name>"<<endl;
        exit(-1);
    }

    World s = World();

    s.run(argv[1],argv[2]);

    return 0;
}