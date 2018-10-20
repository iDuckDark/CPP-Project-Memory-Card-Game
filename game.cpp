//
// Created by iDarkDuck on 2018-10-19.
//

#include <iostream>
#include <string>
#include "game.h"
#include "player.h"
#include "card.h"

//returns a number between 0 and 6 corresponding to the current round of the game
int Game::getRound() {
    return nRound;
}

//which adds a Player to this game.
void Game::addPlayer(const Player &) {

}

Player &Game::getPlayer() {
    return players[players.size() - 1];
}

const Card *Game::getPreviousCard() {
    return &cards[cards.size() - 2];
}

const Card *Game::getCurrentCard() {
    return &cards[cards.size() - 1];
}

void Game::setCurrentCard(const Card *card) {
    Card c = *card;
    return cards.push_back(c);
}