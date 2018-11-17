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

//TODO change to enum class?
enum Side {
    Top, Bottom, Right, Left
};

class Player {

private:
    string name;
    bool active;
    bool endOfGame;
    Side side;
    int nRubies;

    string getSideToString() const;

public:

    explicit Player(const string &);

    string getName() const;

    void setActive(bool);

    bool isActive();

    int getNRubies() const;

    void addReward(const Reward &);

    void setDisplayMode(bool);

    Side getSide() const;

    void setSide(Side);

    friend ostream &operator<<(ostream &, const Player &);

    friend bool operator<(const Player &, const Player &);

    friend bool operator>(const Player &, const Player &);

    friend bool operator==(const Player &, const Player &);
};


#endif //CPP_PROJECT_MEMORY_GAME_PLAYER_H
