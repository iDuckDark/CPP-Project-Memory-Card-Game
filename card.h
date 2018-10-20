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

    enum FaceAnimal {
        Crab, Penguin, Octopus, Turtle, Walrus,
    };


private:
    Card() = default;

    //Note that Penguin and Red are enumeration values of type FaceAnimal and FaceBackground.
    Card(string Penguin, string Red);
};


#endif //CPP_PROJECT_MEMORY_GAME_CARD_H
