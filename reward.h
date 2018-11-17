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

    //TODO make these two private constructor, AFTER fixing class Deck and Emplace Back Method
    Reward(const Reward &);

    Reward &operator=(const Reward &);

private:
    int _nRubies;

    explicit Reward(int);

    //Reward(const Reward &);

    //Reward &operator=(const Reward &);
};


#endif //CPP_PROJECT_MEMORY_GAME_REWARD_H
