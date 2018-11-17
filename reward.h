#ifndef CPP_PROJECT_MEMORY_GAME_REWARD_H
#define CPP_PROJECT_MEMORY_GAME_REWARD_H

#include <iostream>
#include <string>

using namespace std;

class Reward {

private:
    int _nRubies;

    Reward(int);

    //Reward(const Reward &);

public:

    //Reward &operator=(const Reward &);

    friend class RewardDeck;

    int getNRubies() const;

    friend ostream &operator<<(ostream &, const Reward &);

    friend bool operator<(const Reward &, const Reward &);

    friend bool operator>(const Reward &, const Reward &);

    friend bool operator==(const Reward &, const Reward &);
};


#endif //CPP_PROJECT_MEMORY_GAME_REWARD_H
