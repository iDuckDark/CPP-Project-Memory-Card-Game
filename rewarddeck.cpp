#include "rewarddeck.h"

RewardDeck::RewardDeck() : Deck() {
    deck = new vector<Reward *>();
    for (int i = 0; i < 3; i++) deck->emplace_back(new Reward{1});
    for (int i = 0; i < 2; i++) deck->emplace_back(new Reward{2});
    deck->emplace_back(new Reward{3}), deck->emplace_back(new Reward{4});
    Deck<Reward>::shuffle();
}

RewardDeck::~RewardDeck() {
    for (auto &it : *deck) { delete it; };
    delete deck;
}

RewardDeck &RewardDeck::make_RewardDeck() {
    static RewardDeck r;
    r.shuffle();
    return r;
}