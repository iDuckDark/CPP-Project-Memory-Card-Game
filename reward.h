#ifndef CPP_PROJECT_MEMORY_GAME_REWARD_H
#define CPP_PROJECT_MEMORY_GAME_REWARD_H

#include <iostream>
#include <string>

using namespace std;

class Reward {
    friend class RewardDeck;

public:
    int getNRubies() const;

    friend ostream &operator<<(ostream &os, const Reward &reward);

private:
    Reward(int);
    Reward() = default;
    //Reward(const Reward&);
    int _nRubies;


};


#endif //CPP_PROJECT_MEMORY_GAME_REWARD_H
