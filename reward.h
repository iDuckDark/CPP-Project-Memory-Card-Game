#ifndef CPP_PROJECT_MEMORY_GAME_REWARD_H
#define CPP_PROJECT_MEMORY_GAME_REWARD_H

#include <iostream>
#include <string>
#include <cassert>

using namespace std;


class Reward {
private:
    int _nRubies;

    Reward(int);
    //TODO Need to give friend access to RewardDeck, make constructor private
    //Reward(const Reward &);
    //const Reward &operator=(const Reward &);

public:
    friend class RewardDeck;

    //explicit Reward(int);

    int getNRubies() const;

    friend ostream &operator<<(ostream &os, const Reward &reward);
};


#endif //CPP_PROJECT_MEMORY_GAME_REWARD_H
