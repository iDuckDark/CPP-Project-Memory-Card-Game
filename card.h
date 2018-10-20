#ifndef CPP_PROJECT_MEMORY_GAME_CARD_H
#define CPP_PROJECT_MEMORY_GAME_CARD_H

#include <iostream>
#include <string>

using namespace std;
enum FaceAnimal {
    Crab, Penguin, Octopus, Turtle, Walrus
};

enum FaceBackground {
    Red, Green, Purple, Blue, Yellow
};
class Card {

public:
    friend ostream &operator<<(ostream &os, const Card &card);

private:
    Card() = default;

    Card(FaceAnimal faceAnimal, FaceBackground faceBackground);
    FaceAnimal _faceAnimal;
    FaceBackground _faceBackground;
    int _nRows = 3;
    char _color;
    char _animal;
    string operator()(int);
    int getNRows() const;
    char getColor() const ;
    char getAnimal() const;

};


#endif //CPP_PROJECT_MEMORY_GAME_CARD_H
