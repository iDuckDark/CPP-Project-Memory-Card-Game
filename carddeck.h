#ifndef CPP_PROJECT_MEMORY_GAME_CARDDECK_H
#define CPP_PROJECT_MEMORY_GAME_CARDDECK_H


#include <vector>
#include "deck.h"

class CardDeck : public Deck<Card> {
public:
    CardDeck(int);

    void shuffle() override;

    Card* getNext() override;

    bool isEmpty() override;

private:
    vector<Card> deck;
};


#endif //CPP_PROJECT_MEMORY_GAME_CARDDECK_H
