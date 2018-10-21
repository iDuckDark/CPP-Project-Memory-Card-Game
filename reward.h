//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_REWARD_H
#define CPP_PROJECT_MEMORY_GAME_REWARD_H

#include <iostream>
#include <string>

using namespace std;

//Design a class Reward which can take one of four possible values from 1 to 4 rubies. A reward must also
//be printable with the insertion operator cout << reward.
class Reward {
public:
    Reward() = default;
    //Reward(const Reward&);//copy constructor
    explicit Reward(int rubies);
    int getNRubies() const;
    friend ostream &operator<<(ostream &os, const Reward &reward);
private:
    int _nRubies;
};


#endif //CPP_PROJECT_MEMORY_GAME_REWARD_H
