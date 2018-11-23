//
// Created by iDarkDuck on 2018-10-19.
//

#include "carddeck.h"

CardDeck::CardDeck() : Deck() {
    deck = new vector<Card *>();
    for (int i = 0; i != Colors; ++i)
        for (int j = 0; j != Animals; ++j) deck->emplace_back(new Card{(FaceAnimal) j, (FaceBackground) i});
}

CardDeck::~CardDeck() {
    for (auto &it : *deck) { delete it; }
    delete deck;
}

CardDeck &CardDeck::make_CardDeck() {
    static CardDeck c;
    c.shuffle();
    return c;
}