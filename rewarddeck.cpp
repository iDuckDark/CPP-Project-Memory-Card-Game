#include "rewarddeck.h"


RewardDeck::RewardDeck(int num) {
    deck = vector<Reward>(num);
}

void RewardDeck::shuffle() {

}

Reward *RewardDeck::getNext() {
    Reward r;
    return &r;
}

bool RewardDeck::isEmpty() {
    return false;
}
