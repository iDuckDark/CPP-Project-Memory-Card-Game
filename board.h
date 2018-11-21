//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_BOARD_H
#define CPP_PROJECT_MEMORY_GAME_BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "card.h"
#include "carddeck.h"

using namespace std;

enum Letter {
    A = 1, B = 2, C = 3, D = 4, E = 5, Z = -1
};


enum Number {
    One = 1, Two = 2, Three = 3, Four = 4, Five = 5, Zero = -1
};

int toEnum(char &input);

class Board {

private:
    string *screen;

    vector<Card *> cards;

    bool *faceDownCards[5];

    bool *blockedCards[5];

    vector<vector<Card *> *> cards2D;

    int getIndex(const int &, const string &) const;

    void setScreen();

    string *getScreen() const;

    bool isFaceDown(const int &i, const int &y) const;

public:
    Board();

    ~Board();

    bool isFaceUp(const Letter &, const Number &) const;

    bool turnFaceUp(const Letter &, const Number &);

    bool turnFaceDown(const Letter &, const Number &);

    Card *getCard(const Letter &, const Number &);

    void setCard(const Letter &, const Number &, Card *);

    void reset();

    friend ostream &operator<<(ostream &, const Board &);

    bool isValidCard(const Letter &, const Number &) const; //Expert

    void swapCards(const Letter &, const Number &, const Letter &, const Number &); //Expert Octopus

    bool isBlocked(const Letter &, const Number &) const; //Expert Walrus

    void setBlocked(const Letter &, const Number &); //Expert Walrus

    void setUnblocked(const Letter &, const Number &); //Expert Walrus
};

#endif //CPP_PROJECT_MEMORY_GAME_BOARD_H