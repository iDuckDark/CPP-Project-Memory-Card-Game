//
// Created by iDarkDuck on 2018-10-19.
//

#include "carddeck.h"
#define  TEST_CARD_DECK

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

#ifdef TEST_CARD_DECK
#if 1
int main() {
    cout<<"TEST_CARD_DECK"<<endl;
    CardDeck& c = CardDeck::make_CardDeck();

    for(int i =0;i<25;i++){
        cout<<i<<endl;
        Card* card = c.getNext();
           cout<< *card <<endl;
           cout<<"Animal "<<card->getAnimal()<<endl;
           cout<<"Colour "<<card->getColor()<<endl;
           cout<<endl;
    }

}
#endif
#endif