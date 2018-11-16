//
// Created by iDarkDuck on 2018-10-20.
//

#ifndef CPP_PROJECT_MEMORY_GAME_REWARDDECK_H
#define CPP_PROJECT_MEMORY_GAME_REWARDDECK_H


#include "reward.h"
#include "deck.h"

#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

class RewardDeck : public Deck<Reward> {

public:
    RewardDeck();

    ~RewardDeck();
};


#endif //CPP_PROJECT_MEMORY_GAME_REWARDDECK_H
