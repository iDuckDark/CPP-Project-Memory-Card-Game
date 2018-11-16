#include "rewarddeck.h"

RewardDeck::RewardDeck() {
    deck = new vector<Reward>();
    for (int i = 0; i < 3; i++) deck->emplace_back(Reward{1});
    for (int i = 0; i < 2; i++) deck->emplace_back(Reward{2});
    deck->emplace_back(Reward{3});
    deck->emplace_back(Reward{4});
    Deck<Reward>::shuffle();
}

RewardDeck::~RewardDeck() {
    delete deck;
}
