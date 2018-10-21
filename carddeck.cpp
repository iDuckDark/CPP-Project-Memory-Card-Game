//
// Created by iDarkDuck on 2018-10-19.
//

#include "carddeck.h"

CardDeck::CardDeck(int num) {
    deck = vector<Card>(num);
}

void CardDeck::shuffle() {

}

Card CardDeck::getNext() {
    return Card(Crab, Green);
}

bool CardDeck::isEmpty() {
    return false;
}
