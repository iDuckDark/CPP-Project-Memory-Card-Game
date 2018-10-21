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
private:
    int _nRubies;
    friend Reward Reward(int nRubies);



    //Disables the copy contructor
    //Alternative Implementation is     Reward(const Reward &reward)=delete;
    //Reward(const Reward &reward);



public:
    Reward() = default;
    Reward(const Reward&);//copy constructor
    Reward(int nRubies);
    int getNRubies() const;
    friend ostream &operator<<(ostream &os, const Reward &reward);
};


#endif //CPP_PROJECT_MEMORY_GAME_REWARD_H
