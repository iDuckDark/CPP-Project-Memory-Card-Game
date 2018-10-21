//
// Created by iDarkDuck on 2018-10-19.
//

#include <iostream>
#include <string>
#include "game.h"


int Game::getRound() const {
    return nRound;
}

void Game::addPlayer(const Player &player) {
    players.push_back(player);
}

Player &Game::getPlayer() {
    return players[players.size() - 1];
}

vector<Player> Game::getPlayers() const {
    return players;
}

const Card *Game::getPreviousCard() const {

    return cards[cards.size() - 2];
}

const Card *Game::getCurrentCard() const {
    return cards[cards.size() - 1];
}


void Game::setCurrentCard(const Card *card) {
    cards.push_back(card);
}