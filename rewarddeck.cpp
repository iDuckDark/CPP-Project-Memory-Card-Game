#include "rewarddeck.h"

#define TEST_REWARD_DECK

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

#ifdef TEST_REWARD_DECK
#if 0

int main() {
    cout << "TEST_REWARD_DECK" << endl;
    RewardDeck &r = RewardDeck::make_RewardDeck();
    for (int i = 0; i < 7; i++) {
        cout << i << endl;
        Reward *reward = r.getNext();
        cout << *reward << endl;
        cout << "Reward Value " << reward->getNRubies() << endl;
        cout << endl;
    }
    cout << "Testing Completed" << endl;
}

#endif
#endif