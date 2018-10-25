//
// Created by iDarkDuck on 2018-10-19.
//

#include "carddeck.h"
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

CardDeck::CardDeck() {
    deck = new vector<Card>();
    for (int i = 0; i != Colors; ++i) {
        auto color = (FaceBackground) i;
        for (int j = 0; j != Animals; ++j) {
            auto animal = (FaceAnimal) j;
            deck->emplace_back(Card{animal, color});
        }
    }
}

//void CardDeck::shuffle() {
//    std::random_device rd;
//    std::mt19937 g(rd());
//    std::shuffle(deck.begin(), deck.end(), g);
//}
//
//Card *CardDeck::getNext() {
//    if (!deck.empty()) {
//        Card *last = &deck.back();
//        deck.pop_back();
//        return last;
//    }
//    return nullptr;
//}
//
//bool CardDeck::isEmpty() {
//    return deck.empty();
//}

CardDeck& CardDeck::make_CardDeck() {
    static CardDeck c;
    c.shuffle();
    //TODO resolve warning not error: stack memory leak
    return  c;
}

CardDeck::~CardDeck() {
    delete deck;
}
