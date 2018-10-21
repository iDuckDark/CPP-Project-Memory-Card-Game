#include "rewarddeck.h"


RewardDeck::RewardDeck(int num) {
    deck = vector<Reward>(num);
}

void RewardDeck::shuffle() {

}

Reward* RewardDeck::getNext() {
    return &Reward{3};
}

bool RewardDeck::isEmpty() {
    return false;
}
