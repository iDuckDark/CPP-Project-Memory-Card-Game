//
// Created by iDarkDuck on 2018-10-19.
//

#include "game.h"
#include "player.h"
#include "card.h"

//returns a number between 0 and 6 corresponding to the current round of the game

int getRound() {
    return 0;
}

//which adds a Player to this game.
void Game::addPlayer(const Player &) {

}

Player &Game::getPlayer() {

}

const Card *Game::getPreviousCard() {
    return new Card;
}

const Card *Game::getCurrentCard() {
    return new Card;
}

void Game::setCurrentCard(const Card *) {

}