//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_PLAYER_H
#define CPP_PROJECT_MEMORY_GAME_PLAYER_H

#include <vector>
#include "reward.h"

enum class Side {
    Top, Bottom, Left, Right
};

class Player {

private:
    string name;
    bool active;
    bool endOfGame;
    int nRubies;
    Side side;

    string getSideToString() const;

public:

    explicit Player(const string &);

    string getName() const;

    void setActive(const bool &);

    bool isActive() const;

    int getNRubies() const;

    void addReward(const Reward &);

    void setDisplayMode(const bool &);

    Side getSide() const;

    void setSide(const Side &);

    friend ostream &operator<<(ostream &, const Player &);

    friend bool operator<(const Player &, const Player &);

    friend bool operator>(const Player &, const Player &);

    friend bool operator==(const Player &, const Player &);
};

#endif //CPP_PROJECT_MEMORY_GAME_PLAYER_H
