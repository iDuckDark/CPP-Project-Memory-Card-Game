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

private:

    Card(const FaceAnimal &faceAnimal, const FaceBackground &faceBackground);

    Card(const Card &);

    Card &operator=(const Card &);

    FaceAnimal _faceAnimal;
    FaceBackground _faceBackground;
    int _nRows = 3;
    char _color;
    char _animal;

    int getNRows() const;

public:

    friend class CardDeck;

    string operator()(const int &) const;

    friend ostream &operator<<(ostream &, const Card &);

    friend bool operator==(const Card &, const Card &);

    explicit operator FaceBackground();

    explicit operator FaceAnimal();

    char getColor() const;

    char getAnimal() const;
};

#endif //CPP_PROJECT_MEMORY_GAME_CARD_H
