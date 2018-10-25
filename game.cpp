//
// Created by iDarkDuck on 2018-10-19.
//

#include <iostream>
#include <string>
#include "game.h"

int Game::getRound() const {
    return nRound;
}

Board &Game::getBoard() {
    return board;
}

int Game::getNPlayers() const {
    return playersQueue.size();
}

void Game::setRound(int num) {
    nRound = num;
}

void Game::addPlayer(const Player &player) {
    playersQueue.push(player);
}

Player &Game::getPlayer() {
    currentPlayer = playersQueue.front();
    playersQueue.pop();
    addPlayer(currentPlayer);
    return currentPlayer;
}

void Game::setAllPlayersActive() const {
    queue tempQueue = playersQueue;
    while (!tempQueue.empty()) {
        tempQueue.front().setActive(true);
        tempQueue.pop();
    }
}

int Game::getNActivePlayers() const {
    queue tempQueue = playersQueue;
    int nActivePlayers;
    while (!tempQueue.empty()) {
        if (tempQueue.front().isActive()) {
            nActivePlayers++;
        }
        tempQueue.pop();
    }
    return nActivePlayers;
}

//TODO need to make pairs with Card and Players
const Card *Game::getPreviousCard() const {
    return cards[cards.size() - 2];
}

//TODO need to make pairs with Card and Players
const Card *Game::getCurrentCard() const {
    return cards[cards.size() - 1];
}

//TODO need to make pairs with Card and Players
void Game::setCurrentCard(const Card *card) {
    cards.push_back(card);
}

ostream &operator<<(ostream &os, const Game &game) {
    os << game.board << endl;
    queue tempQueue = game.playersQueue;
    while (!tempQueue.empty()) {
        os << tempQueue.front() << endl;
        tempQueue.pop();
    }
    return os;
}