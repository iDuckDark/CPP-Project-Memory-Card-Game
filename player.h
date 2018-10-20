//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_PLAYER_H
#define CPP_PROJECT_MEMORY_GAME_PLAYER_H


#include <string>
#include "reward.h"


using namespace std;

class Player {

    //return the name of the player.
    string getName() const;

    //set the status of the player as active or inactive.
    void setActive(bool);

    //returns true if the player is active.
    bool isActive();

    //return the number of rubies won by this player.
    int getNRubies() const;

    //add a reward with a given number of rubies.
    void addReward(const Reward &);

    //add a reward with a given number of rubies.
    void setDisplayMode(bool endOfGame);

    void print();
};


#endif //CPP_PROJECT_MEMORY_GAME_PLAYER_H
