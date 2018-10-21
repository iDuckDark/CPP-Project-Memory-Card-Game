//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_BOARD_H
#define CPP_PROJECT_MEMORY_GAME_BOARD_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "carddeck.h"

using namespace std;

enum Letter {
    A = 'A', B = 'B', C = 'C', D = 'D', E = 'E'
};

enum Number {
    One = 1, Two = 2, Three = 3, Four = 4, Five = 5
};

//Design a class Board which holds an array of strings corresponding to the screen display of the game.
class Board {

private:
    string* screen;

public:
    Board();

    ~Board();

    string * getScreen() const;
    //Board() = default;

    void setScreen();

    bool isFaceUp(const Letter &, const Number &) const;

    bool turnFaceUp(const Letter &, const Number &);

    bool turnFaceDown(const Letter &, const Number &);

    void reset();

    friend ostream &operator<<(ostream &os, const Board &board);
};

#endif //CPP_PROJECT_MEMORY_GAME_BOARD_H
