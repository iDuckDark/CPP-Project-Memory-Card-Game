//
// Created by iDarkDuck on 2018-10-20.
//

#ifndef CPP_PROJECT_MEMORY_GAME_REWARDDECK_H
#define CPP_PROJECT_MEMORY_GAME_REWARDDECK_H

#include <vector>
#include "reward.h"
#include "deck.h"


using namespace std;

//Design a class RewardDeck derived from Deck<Reward> with the corresponding properties to CardDeck.
class RewardDeck : public Deck<Reward> {
    friend class Reward;

public:
//    Reward* getNext() override;

//    bool isEmpty() override;

    RewardDeck();
    ~RewardDeck();

//    void shuffle() override;

    vector<Reward>* deck;
private:
};


#endif //CPP_PROJECT_MEMORY_GAME_REWARDDECK_H
