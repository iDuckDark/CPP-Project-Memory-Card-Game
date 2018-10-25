#include "rewarddeck.h"
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>


RewardDeck::RewardDeck() {
    deck = new vector<Reward>();
    for(int i=0;i<3;i++){
        deck->emplace_back(Reward{1});
    }
    for(int i=0;i<2;i++){
        deck->emplace_back(Reward{2});
    }
    deck->emplace_back(Reward{3});
    deck->emplace_back(Reward{4});

}
RewardDeck::~RewardDeck() {
    delete deck;
}

//void RewardDeck::shuffle() {
//    std::random_device rd;
//    std::mt19937 g(rd());
//    std::shuffle(deck.begin(), deck.end(), g);
//}
//
//Reward *RewardDeck::getNext() {
//    if (!deck.empty()) {
//        Reward *last = &deck.back();
//        //TODO Verify with prof if we really need to pop?
//        deck.pop_back();
//        return last;
//    }
//    return nullptr;
//}
//
//bool RewardDeck::isEmpty() {
//    return deck.empty();
//}
