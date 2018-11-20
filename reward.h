#ifndef CPP_PROJECT_MEMORY_GAME_REWARD_H
#define CPP_PROJECT_MEMORY_GAME_REWARD_H

#include <iostream>
#include <string>

using namespace std;

class RewardDeck;

class Reward {
    friend class RewardDeck;

public:
    int getNRubies() const;

    friend ostream &operator<<(ostream &, const Reward &);

    friend bool operator<(const Reward &, const Reward &);

    friend bool operator>(const Reward &, const Reward &);

    friend bool operator==(const Reward &, const Reward &);

    Reward &operator=(const int &x); // conversion from int (assignment):

    operator int();     //conversion to int (type-cast operator)

private:

    int _nRubies;

    explicit Reward(const int &);

    Reward(const Reward &);

    Reward &operator=(const Reward &);

};


#endif //CPP_PROJECT_MEMORY_GAME_REWARD_H
