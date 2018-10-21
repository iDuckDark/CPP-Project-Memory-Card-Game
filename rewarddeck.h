//
// Created by iDarkDuck on 2018-10-20.
//

#ifndef CPP_PROJECT_MEMORY_GAME_REWARDDECK_H
#define CPP_PROJECT_MEMORY_GAME_REWARDDECK_H

#include <vector>
#include "reward.h"
#include "deck.h"

//Design a class RewardDeck derived from Deck<Reward> with the corresponding properties to CardDeck.
class RewardDeck : public Deck<Reward> {
    friend class Reward;

public:
    RewardDeck() = default;

    explicit RewardDeck(int);

    void shuffle() override;

    Reward* getNext() override;

    bool isEmpty() override;

private:
    vector<Reward> deck;
};


#endif //CPP_PROJECT_MEMORY_GAME_REWARDDECK_H
