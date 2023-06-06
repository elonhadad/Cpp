//
// Created by ELON HADAD on 27/11/2022.
//

#ifndef EX_02_CELL_H
#define EX_02_CELL_H

class Cell {

/**
 * in this class we are not allocating any memory and for that reason we can use the default destructor.
 * that is why we can use the role of 0 and we have no need to write any of the big 5.
 */

public:

    Cell();

    /**
     * @return - Cell value.
     */
    char getC() const;

    /**
     * set char into cell value.
     * @param c = char value for Cell.
     */
    void setC(char c);

    /**
     * increment by 1 the red/blue field.
     * @param player = boolean flag from the Alchemize class which player is playing.
     */
    void increment(bool player);

    /**
     * decrement by 1 the red/blue field.
     * @param player = boolean flag from the Alchemize class which player is playing.
     */
    void decrement(bool player);

    /**
     * checking all game condition and update all counters.
     * @param p1 = player 1 (Red) counter.
     * @param p2 = player 2 (Blue) counter.
     * @param board = board game counter.
     * @param player = boolean flag from the Alchemize class which player is playing.
     */
    void compare(int &p1, int &p2, int &board , bool player);

private:

    char c;
    int blue;
    int red;
};

#endif //EX_02_CELL_H