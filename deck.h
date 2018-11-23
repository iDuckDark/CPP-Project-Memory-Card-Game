//
// Created by iDarkDuck on 2018-10-20.
//

#ifndef CPP_PROJECT_MEMORY_GAME_DECK_H
#define CPP_PROJECT_MEMORY_GAME_DECK_H

#include <algorithm>
#include <iterator>
#include <random>
#include <vector>

#include "card.h"
#include "reward.h"

template<class C>


class Deck {

public:
    Deck() = default;

    void shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(deck->begin(), deck->end(), g);
    }

    C *getNext() {
        if (!(*deck).empty()) {
            C *last = deck->back();
            deck->pop_back();
            return last;
        }
        return nullptr;
    }

    bool isEmpty() { return (*deck).empty(); }

    virtual ~Deck() = default;

protected:
    vector<C *> *deck;
};


#endif //CPP_PROJECT_MEMORY_GAME_DECK_H
