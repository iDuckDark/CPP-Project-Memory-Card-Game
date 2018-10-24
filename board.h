//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_BOARD_H
#define CPP_PROJECT_MEMORY_GAME_BOARD_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "card.h"
#include "carddeck.h"

using namespace std;

enum Letter {
    A = 'A', B = 'B', C = 'C', D = 'D', E = 'E'
};

enum Number {
    One = 1, Two = 2, Three = 3, Four = 4, Five = 5
};

class Board {

private:
    string *screen;

    bool *faceDownCards[5];

    int getRowIndex(const Letter &letter) const;

    int getColIndex(const Number &number) const;

    int getStringRowIndex(const Letter &letter) const;

    int getStringColIndex(const Number &number) const;

public:
    Board();

    ~Board();

    string *getScreen() const;

    string getScreenRow(int row) const;

    bool *getIsFaceDownCards() const;

    void setScreen();

    bool isFaceUp(const Letter &letter, const Number &number) const;

    bool isFaceDown(int i, int y) const;

    bool turnFaceUp(const Letter &letter, const Number &number);

    bool turnFaceDown(const Letter &letter, const Number &number);

    void reset();

    friend ostream &operator<<(ostream &os, const Board &board);
};

#endif //CPP_PROJECT_MEMORY_GAME_BOARD_H
