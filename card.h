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
    friend class CardDeck;
public:
    friend ostream &operator<<(ostream &os, const Card &card);
    string operator()(int) const ;
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

    int getNRows() const;

};


#endif //CPP_PROJECT_MEMORY_GAME_CARD_H
