#ifndef CPP_PROJECT_MEMORY_GAME_CARDDECK_H
#define CPP_PROJECT_MEMORY_GAME_CARDDECK_H


#include <vector>
#include "deck.h"

class CardDeck : public Deck<Card> {
public:
    CardDeck();

    Card *getNext() override;

    vector<Card> deck;

    static CardDeck &make_CardDeck();

    void shuffle() override;

    bool isEmpty() override;

private:
    //CardDeck(); //TODO private contructor

    //CardDeck(const CardDeck &);
};


#endif //CPP_PROJECT_MEMORY_GAME_CARDDECK_H
