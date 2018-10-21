//
// Created by iDarkDuck on 2018-10-20.
//

#ifndef CPP_PROJECT_MEMORY_GAME_REWARDDECK_H
#define CPP_PROJECT_MEMORY_GAME_REWARDDECK_H

#include "reward.h"
#include "deck.h"

//Design a class RewardDeck derived from Deck<Reward> with the corresponding properties to CardDeck.
class RewardDeck:public Deck<Reward>  {
    RewardDeck() = default;

    void shuffle() = 0;

    Reward getNext();

    bool isEmpty();
};


#endif //CPP_PROJECT_MEMORY_GAME_REWARDDECK_H
