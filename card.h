#ifndef CPP_PROJECT_MEMORY_GAME_CARD_H
#define CPP_PROJECT_MEMORY_GAME_CARD_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

enum FaceAnimal {
    Crab, Penguin, Octopus, Turtle, Walrus, Animals
};

enum FaceBackground {
    Red, Green, Purple, Blue, Yellow, Colors
};

class Card {

public:
    friend class CardDeck;

    string operator()(int) const;

    friend ostream &operator<<(ostream &, const Card &);

    friend bool operator==(const Card &, const Card &);

    char getColor() const;

    char getAnimal() const;

private:

    Card(FaceAnimal faceAnimal, FaceBackground faceBackground);

    Card(const Card &);

    Card &operator=(const Card &);

    FaceAnimal _faceAnimal;

    FaceBackground _faceBackground;

    int _nRows = 3;

    char _color;

    char _animal;

    int getNRows() const;
};

#endif //CPP_PROJECT_MEMORY_GAME_CARD_H
