//
// Created by iDarkDuck on 2018-10-19.
//

#include "carddeck.h"

using namespace std;

CardDeck::CardDeck() : Deck() {
    deck = new vector<Card>();
    for (int i = 0; i != Colors; ++i) {
        auto color = (FaceBackground) i;
        for (int j = 0; j != Animals; ++j) {
            auto animal = (FaceAnimal) j;
            deck->emplace_back(Card{animal, color});
        }
    }
}

CardDeck::~CardDeck() {
    delete deck;
}

CardDeck& CardDeck::make_CardDeck() {
    static CardDeck c;
    c.shuffle();
    //TODO resolve warning not error: stack memory leak
    return  c;
}