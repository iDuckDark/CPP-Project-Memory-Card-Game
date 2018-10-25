//
// Created by iDarkDuck on 2018-10-20.
//

#ifndef CPP_PROJECT_MEMORY_GAME_DECK_H
#define CPP_PROJECT_MEMORY_GAME_DECK_H


#include "card.h"
#include "reward.h"
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

template<class C>
class Deck {


public:
    Deck() = default;

//    //TODO : Ask Prof is this private or public???
//    void shuffle() = 0;
//
//    C *getNext() = 0;
//
//    bool isEmpty() = 0;

    void shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(deck->begin(), deck->end(), g);
    }

    C* getNext() {
        if (!(*deck).empty()) {
            Card *last = &(*deck).back();
            deck->pop_back();
            return last;
        }
        return nullptr;
    }

    bool isEmpty() {
        return (*deck).empty();
    }

protected:
    vector<C>* deck = new vector<C>();

};


#endif //CPP_PROJECT_MEMORY_GAME_DECK_H
