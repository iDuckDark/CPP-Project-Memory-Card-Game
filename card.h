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
    friend Card Card(FaceAnimal faceAnimal, FaceBackground faceBackground);//Constructor

private:
    Card(FaceAnimal faceAnimal, FaceBackground faceBackground);
    Card() = default;
    Card(const Card&);//making copy constructor private


    FaceAnimal _faceAnimal;
    FaceBackground _faceBackground;
    int _nRows = 3;
    char _color;
    char _animal;

    char getColor() const ;
    char getAnimal() const;
    string operator()(int) const ;
    int getNRows() const;

};


#endif //CPP_PROJECT_MEMORY_GAME_CARD_H
