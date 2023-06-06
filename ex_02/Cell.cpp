//
// Created by ELON HADAD on 27/11/2022.
//

#include "Cell.h"

Cell::Cell() {
    this->c = 'O';
    this->red = 0;
    this->blue = 0;
}

char Cell::getC() const {
    return c;
}

void Cell::setC(char i) {
    Cell::c = i;
}

void Cell::increment(bool player){
    if(player)
        this->red += 1;
    else
        this->blue +=1;
}

void Cell::decrement(bool player)  {
    if(player)
        this->red -= 1;
    else
        this->blue -=1;
}

void Cell::compare(int &p1, int &p2 , int &board , bool player){

    // Red player
    if(player) {
        if (this->c == 'r') {
            setC('X');
            p1--;
        }
        if (this->red == 2 && this->c == 'O') {
            setC('X');
            board--;
        }
        if (this->red == 2 && this->c == 'b') {
            setC('X');
            p2--;
        }
        if (this->blue == 1 && this->c == 'O') {
            setC('r');
            decrement(player);
            board--;
            p1++;
        }
    }
    // Blue player
    else {
        if (this->c == 'b') {
            setC('X');
            p2--;
        }
        if (this->blue == 2 && this->c == 'O') {
            setC('X');
            board--;
        }

        if (this->blue == 2 && this->c == 'r') {
            setC('X');
            p1--;
        }
        if (this->red == 1 && this->c == 'O') {
            setC('b');
            decrement(player);
            board--;
            p2++;
        }
    }
}