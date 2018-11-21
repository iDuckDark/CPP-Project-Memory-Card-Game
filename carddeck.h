#ifndef CPP_PROJECT_MEMORY_GAME_CARDDECK_H
#define CPP_PROJECT_MEMORY_GAME_CARDDECK_H

#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include "deck.h"

class CardDeck : public Deck<Card> {

public:

    ~CardDeck() override;

    static CardDeck &make_CardDeck();

private:

    CardDeck();

    CardDeck(const CardDeck &);

    CardDeck &operator=(const CardDeck &);
};


#endif //CPP_PROJECT_MEMORY_GAME_CARDDECK_H
