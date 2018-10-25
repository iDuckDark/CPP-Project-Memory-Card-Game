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
    vector<const Card *> cardVector;
    cardQueue.push(cardVector);
}

Player &Game::getPlayer() {
    Player &currentPlayer = playersQueue.front(); //{Peter, Nevin ,Div}
    playersQueue.pop(); //{Nevin ,Div}
    playersQueue.push(currentPlayer); //{ Nevin ,Div,Peter}

    vector<const Card *> cardVector = cardQueue.front(); //Cards :{Peter, Nevin ,Div}
    cardQueue.pop(); //Cards :{ Nevin ,Div}
    cardQueue.push(cardVector);
    return currentPlayer;
}

bool Game::twoCardsSelected() const {
    return (cardQueue.back().size() == 2);
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
    int nActivePlayers = 0;
    while (!tempQueue.empty()) {
        if (tempQueue.front().isActive()) {
            nActivePlayers++;
        }
        tempQueue.pop();
    }
    cout << "N ACTIVE PLAYERS: " << nActivePlayers << endl;
    return nActivePlayers;
}

const Card *Game::getPreviousCard() const {
    vector<const Card *> cardVector = cardQueue.back(); //peter's cards
    const Card *previousCard = cardVector[0]; //peter's first card
    return previousCard;
}

const Card *Game::getCurrentCard() const {
    vector<const Card *> cardVector = cardQueue.back(); //peter's cards
    const Card *currentCard = cardVector[1]; //peter's second card
    return currentCard;
}

void Game::setCurrentCard(const Card *card) {
    // Players Queue after getNext : {  Nevin, Div , Peter}
    vector<const Card *> cardVector = cardQueue.back(); //peter's cards
    cardVector.push_back(card); //Add a card
    cardQueue.back() = cardVector;  //Updates Peter's Cards
    //cout << "PETERRRRRRRRRRRR BJT!!!" << endl;
    //cout << *cardQueue.back()[0] << endl;
}

void Game::clearSelectedCards() {
    vector<const Card *> cardVector = cardQueue.back(); //peter's cards
    cardVector.pop_back(); //Removes two cards
    cardVector.pop_back();
    cardQueue.back() = cardVector;  //Updates Peter's Cards
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