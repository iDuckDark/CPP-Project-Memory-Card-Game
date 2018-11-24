//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_PLAYER_H
#define CPP_PROJECT_MEMORY_GAME_PLAYER_H

#include <vector>
#include "reward.h"

//TODO change to enum class?
//enum Side {
//    Top = 0, Bottom = 1, Left = 2, Right = 3
//};

enum class Side { Top, Bottom, Left, Right };

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
