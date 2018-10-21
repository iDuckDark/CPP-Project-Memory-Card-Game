#ifndef CPP_PROJECT_MEMORY_GAME_REWARD_H
#define CPP_PROJECT_MEMORY_GAME_REWARD_H

#include <iostream>
#include <string>

using namespace std;
//TODO Need to give friend access to RewardDeck, make constructor private

class Reward {


public:
    int getNRubies() const;

    friend ostream &operator<<(ostream &os, const Reward &reward);
    //Reward(const Reward&);
    int _nRubies;


    explicit Reward(int);
    Reward() = default;
private:


};


#endif //CPP_PROJECT_MEMORY_GAME_REWARD_H
