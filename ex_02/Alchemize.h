//
// Created by ELON HADAD on 27/11/2022.
//

#ifndef EX_02_ALCHEMIZE_H
#define EX_02_ALCHEMIZE_H
#include <iostream>
#include "Cell.h"

class Alchemize {

public:

    explicit Alchemize(int size);                       // default constructor.

    Alchemize(const Alchemize& other);                  // copy constructor.

    Alchemize(Alchemize&& other) noexcept;              // move constructor.

    Alchemize& operator=(const Alchemize& other);       // copy assignment operator.

    Alchemize& operator=(Alchemize&& other) noexcept;   // move assignment operator.

    void run_game();                                    // staring the game.

    ~Alchemize();                                       // destructor.

private:

    /**
     * Checking the correctness of the input, whether the slot is empty,
     * whether the coordinates are within the range of the game board.
     * @param row = int number from player for row.
     * @param col = int number from player for column.
     * @return = boolean.
     */
    bool validate_input(int row, int col);

    /**
     * searching for all Cell neighbors and send each of them to check the condition.
     * @param row = int number from player for row.
     * @param col = int number from player for column.
     * @param player = boolean flag from the Alchemize class which player is playing.
     */
    void assign_neighbours(int row, int col, bool player);

    /**
     * printing board and players cristal counters.
     */
    void print_board() const;

    /**
     * printing at the end of the game who's the winner.
     */
    void print_winner() const;

    int size;
    int p1_count;
    int p2_count;
    int board_count;
    Cell** board;

};

#endif //EX_02_ALCHEMIZE_H