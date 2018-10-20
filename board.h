//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_BOARD_H
#define CPP_PROJECT_MEMORY_GAME_BOARD_H

#include <iostream>
#include <string>

using namespace std;

enum Letter {
    crab = 'C', penguin = 'P', octopus = 'O', turtle = 'T', walrus = 'W'
};

enum Number {
    one = 1, two = 2, three = 3, four = 4, five = 5
};

//Design a class Board which holds an array of strings corresponding to the screen display of the game.
class Board {

private:
    string screen[];

public:
    Board() = default;

    Board
    bool isFaceUp(const char &Letter, const int &Number) const;

    bool turnFaceUp(const char &Letter, const int &Number);

    bool turnFaceDown(const char &Letter, const int &Number);

    void reset();

    friend ostream &operator<<(ostream &os, const Board &player);
};

#endif //CPP_PROJECT_MEMORY_GAME_BOARD_H
