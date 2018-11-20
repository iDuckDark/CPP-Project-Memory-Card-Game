#ifndef CPP_PROJECT_MEMORY_GAME_CARD_H
#define CPP_PROJECT_MEMORY_GAME_CARD_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

enum FaceAnimal {
    Crab = 1, Penguin = 2, Octopus = 3, Turtle = 4, Walrus = 5, Animals = 6
};

enum FaceBackground {
    Red = 1, Green = 2, Purple = 3, Blue = 4, Yellow = 5, Colors = 6
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
    //TODO Need to make copy constructor and assignment operator private

    FaceAnimal _faceAnimal;

    FaceBackground _faceBackground;
    int _nRows = 3;

    char _color;

    char _animal;

    int getNRows() const;
};

#endif //CPP_PROJECT_MEMORY_GAME_CARD_H
