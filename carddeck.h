#ifndef CPP_PROJECT_MEMORY_GAME_CARDDECK_H
#define CPP_PROJECT_MEMORY_GAME_CARDDECK_H


#include <vector>
#include "deck.h"

class CardDeck : public Deck<Card> {
public:
    CardDeck();
    ~CardDeck();


    static CardDeck &make_CardDeck();

    //CardDeck(); //TODO private contructor






private:

    //CardDeck(const CardDeck &);
};


#endif //CPP_PROJECT_MEMORY_GAME_CARDDECK_H
