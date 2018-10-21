//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_BOARD_H
#define CPP_PROJECT_MEMORY_GAME_BOARD_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

enum Letter {
    Crab = 'C', Penguin = 'P', Octopus = 'O', Turtle = 'T', Walrus = 'W', FaceDown = 'Z'
};

enum Number {
    One = 1, Two = 2, Three = 3, Four = 4, Five = 5
};

//Design a class Board which holds an array of strings corresponding to the screen display of the game.
class Board {

private:
    string screen[19][19];

public:
    Board() = default;

    bool isFaceUp(const Letter &, const Number &) const;

    bool turnFaceUp(const Letter &, const Number &);

    bool turnFaceDown(const Letter &, const Number &);

    void reset();

    friend ostream &operator<<(ostream &os, const Board &player);
};

#endif //CPP_PROJECT_MEMORY_GAME_BOARD_H
