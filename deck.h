//
// Created by iDarkDuck on 2018-10-20.
//

#ifndef CPP_PROJECT_MEMORY_GAME_DECK_H
#define CPP_PROJECT_MEMORY_GAME_DECK_H


#include "card.h"
#include "reward.h"


template<class C>
class Deck {


public:
    Deck() = default;

    virtual void shuffle() = 0;

    virtual C getNext();

    virtual bool isEmpty();


protected:
    C* card;
};


#endif //CPP_PROJECT_MEMORY_GAME_DECK_H
