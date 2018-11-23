//
// Created by iDarkDuck on 2018-11-18.
//
//
//#include "deck.h"
//
//
//template<class C>
//
//void Deck<C>::shuffle() {
//    std::random_device rd;
//    std::mt19937 g(rd());
//    std::shuffle(deck->begin(), deck->end(), g);
//}
//
//template<class C>
//
//C *Deck<C>::getNext() {
//    if (!(*deck).empty()) {
//        C *last = deck->back();
//        deck->pop_back();
//        return last;
//    }
//    return nullptr;
//}
//
//template<class C>
//
//bool Deck<C>::isEmpty() { return (*deck).empty(); }
//
//virtual Deck::~Deck() {};