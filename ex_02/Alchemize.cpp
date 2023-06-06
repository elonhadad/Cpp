//
// Created by ELON HADAD on 27/11/2022.
//

#include "Alchemize.h"
#include "Cell.h"
#include <sstream>
#include <string>

Alchemize::Alchemize(int size) {
    this->size = size;
    this->p1_count = 0;
    this->p2_count = 0;
    this->board_count = size * size;

    this->board = new Cell*[this->size];
    for (int i = 0; i < size ; i++){
        this->board[i] = new Cell[this->size];
    }
}

Alchemize::Alchemize(const Alchemize &other) {
    this->size = other.size;
    this->p2_count = other.p2_count;
    this->p1_count = other.p1_count;
    this->board_count = other.size * other.size;

    this->board = new Cell*[other.size];
    for (int i = 0; i < size ; i++){
        this->board[i] = new Cell[other.size];
        for(int j = 0; j < size; j++) {
            this->board[i][j] = other.board[i][j];
        }
    }
}

Alchemize::Alchemize(Alchemize &&other) noexcept{
    this->size = other.size;
    this->p1_count = other.p1_count;
    this->p2_count = other.p2_count;
    this->board_count = other.board_count;
    this->board = other.board;

    for (int i = 0; i < other.size; i++){
        other.board[i]= nullptr;
    }
    other.board = nullptr;
}

Alchemize &Alchemize::operator=(const Alchemize &other) {
    if (this == &other)
        return *this;

    size = other.size;
    p2_count = other.p2_count;
    p1_count = other.p1_count;
    board_count = other.size * other.size;

    for (int i = 0; i < size; i++)
        delete[] board[i];

    delete[] board;

    this->board = new Cell*[other.size];
    for (int i = 0; i < other.size; i++) {
        this->board[i] = new Cell[other.size];
        for (int j = 0; j < other.size; ++j)
            board[i][j] = other.board[i][j];
    }
    return *this;
}

Alchemize &Alchemize::operator=(Alchemize &&other) noexcept {

    this->size = other.size;
    this->p1_count = other.p1_count;
    this->p2_count = other.p2_count;
    this->board_count = other.board_count;
    this->board = other.board;

    for (int i = 0; i < other.size; i++){
        other.board[i]= nullptr;
    }
    other.board = nullptr;

    return *this;
}

void Alchemize::run_game() {
    std::string user_c;
    std::stringstream s;
    bool red_flag = true;

    print_board();

    while (board_count){
        int row = 0;
        int col = 0;

        if (red_flag)
            std::cout << "R:\n";
        else
            std::cout << "B:\n";

        s.clear();
        getline(std::cin,user_c);
        s << user_c;
        s >> row;
        s >> col;
        row -= 1;
        col -= 1;

        if (!validate_input(row, col))
            continue;

        if (red_flag)
            board[row][col].setC('R');
        else
            board[row][col].setC('B');

        board_count--;

        assign_neighbours(row,col, red_flag);
        print_board();
        red_flag = !red_flag;
    }
    print_winner();
}

bool Alchemize::validate_input(int row , int col) {
    if (row <= (size -1) && col <= (size -1) && board[row][col].getC() == 'O')
        return true;

    std::cerr << "Invalid row/col index or non free cell" << std::endl;
    return false;
}

void Alchemize::assign_neighbours(int row, int col, bool player) {
    int offset_x[] = {0,1,1,1,0,-1,-1,-1};
    int offset_y[] = {-1,-1,0,1,1,1,0,-1};

    for (int i = 0; i < 8; i++) {
        int x = col + offset_x[i];
        int y = row + offset_y[i];

        if (x < 0 || x > (size - 1) || y < 0 || y > (size - 1))     // checking out of bounds
            continue;

        this->board[y][x].increment(player);
        this->board[y][x].compare(p1_count,p2_count,board_count,player);
    }
}

void Alchemize::print_board() const {
    std::cout << "Red count: " << p1_count << "\t" << "Blue count: " << p2_count << std::endl;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << board[i][j].getC() << "\t";
        }
        std::cout << "\n";
    }
}

void Alchemize::print_winner() const  {
    if (p1_count > p2_count)
        std::cout << "Red won" << std::endl;
    else if (p1_count < p2_count)
        std::cout << "Blue won" << std::endl;
    else
        std::cout << "The game ended with tie" << std::endl;
}

Alchemize::~Alchemize() {
    for (int i = 0; i < size; i++)
        delete[] board[i];

    delete[] board;
}