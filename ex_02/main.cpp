#include <iostream>
#include "Alchemize.h"

int main(int argc, char* argv[]) {
    if (argc != 2){
        std::cerr <<"Invalid run arguments; run the game with board size.\n";
        exit(0);
    }

    Alchemize* game;
    game = new Alchemize(std::stoi(argv[1]));
    game->run_game();

    delete game;

    return 0;
}