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
//TODO Need to give friend access to CardDeck,make constructor private
class Card {
public:
    friend ostream &operator<<(ostream &os, const Card &card);
    string operator()(int) const ;

    Card(FaceAnimal faceAnimal, FaceBackground faceBackground);
    Card() = default;
private:
    Card(const Card&);//making copy constructor private
    friend  class CardDeck;


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
