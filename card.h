//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_CARD_H
#define CPP_PROJECT_MEMORY_GAME_CARD_H

#include <iostream>
#include <string>

using namespace std;
//Design a class Card which can take a face of one of the five possible animals and one of the five
//background colours. A card must also be “printable” as one string per row with the method:

class Card {

    //Note that Penguin and Red are enumeration values of type FaceAnimal and FaceBackground.

    enum FaceAnimal {
        Crab, Penguin, Octopus, Turtle, Walrus
    };

    enum FaceBackground {
        red, green, purple, blue, yellow
    };


private:
    FaceAnimal  faceAnimal;
    FaceBackground faceBackground;
    int nRows;
    Card() = default;
    Card(int nRows);
    Card(FaceAnimal faceAnimal, FaceBackground faceBackground);
    int getNRows() const;
public:

    friend ostream &operator<<(ostream &os, const Card &card);
};


#endif //CPP_PROJECT_MEMORY_GAME_CARD_H
