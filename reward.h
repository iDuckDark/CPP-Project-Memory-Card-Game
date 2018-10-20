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
    int nRubies;



    //Disables the copy contructor
    //Alternative Implementation is     Reward(const Reward &reward)=delete;
    //Reward(const Reward &reward);

    int getNRubies() const;

public:
    Reward() = default;

    Reward(int nRubies);

    friend ostream &operator<<(ostream &os, const Reward &player);
};


#endif //CPP_PROJECT_MEMORY_GAME_REWARD_H
