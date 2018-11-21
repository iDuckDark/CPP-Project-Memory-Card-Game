//
// Created by iDarkDuck on 2018-10-20.
//

#ifndef CPP_PROJECT_MEMORY_GAME_REWARDDECK_H
#define CPP_PROJECT_MEMORY_GAME_REWARDDECK_H

#include "deck.h"
#include "reward.h"

#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

class RewardDeck : public Deck<Reward> {

public:

    ~RewardDeck() override;

    static RewardDeck &make_RewardDeck();

private:

    RewardDeck();

    RewardDeck(const RewardDeck &);

    RewardDeck &operator=(const RewardDeck &);
};


#endif //CPP_PROJECT_MEMORY_GAME_REWARDDECK_H
