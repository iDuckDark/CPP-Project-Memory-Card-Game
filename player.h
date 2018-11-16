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

enum class Side {
    Top, Bottom, Right, Left
};

class Player {

private:
    string name;
    bool active;
    bool endOfGame;
    Side side;
    string sideOfTheBoard;
    int nRubies;

public:

    Player() = default;

    Player(string name);

    Player(string name, Side sideOfTheBoard);

    Player(string name, string sideOfTheBoard);

    string getName() const;

    void setActive(bool);

    bool isActive();

    int getNRubies() const;

    void addReward(const Reward &);

    void setDisplayMode(bool);

    Side getSide() const;

    void setSide(Side);

    friend ostream &operator<<(ostream &os, const Player &player);

    friend bool operator<(const Player &lhs, const Player &rhs);

    friend bool operator>(const Player &lhs, const Player &rhs);

    friend bool operator==(const Player &lhs, const Player &rhs);

    string getSideOfTheBoard() const;
};


#endif //CPP_PROJECT_MEMORY_GAME_PLAYER_H
