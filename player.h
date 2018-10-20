//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_PLAYER_H
#define CPP_PROJECT_MEMORY_GAME_PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "reward.h"

using namespace std;

class Player {
    Player() = default;

    Player(string name, string sideOfTheBoard, int nRubies);

private:
    string name;
    bool active;
    vector<Reward> rewards;
    bool endOfGame;
    string sideOfTheBoard; //Not sure why is this needed but leave it for now
    int nRubies;

public:

    string getName() const;

    void setActive(bool);

    bool isActive();

    int getNRubies() const;

    void addReward(const Reward &);

    void setDisplayMode(bool endOfGame);

    friend ostream &operator<<(ostream &os, const Player &player);

    //Added Own Functions
    bool getEndOfGame() const;
};


#endif //CPP_PROJECT_MEMORY_GAME_PLAYER_H
