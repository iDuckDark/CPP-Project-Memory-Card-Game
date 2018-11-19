//
// Created by iDarkDuck on 2018-10-19.
//

#include <iostream>
#include <string>
#include "game.h"

void Game::setRound(int &num) { nRound = num; }

int Game::getRound() const { return nRound; }

void Game::addPlayer(const Player &player) {
    players.push_back(player);
    vector<const Card *> cardVector;
    cards.push_back(cardVector);
}

void Game::setSide(Side side) { currentSide = side; }

Player &Game::getPlayer(Side side) {
    for (auto &player: players) {
        if (player.getSide() == side) {
            setSide(side);
            return player;
        }
    }
    throw out_of_range("Invalid Player");
}

const Card *Game::getPreviousCard() const {
    vector<const Card *> cardVector = cards[currentSide];
    const Card *previousCard = cardVector[0];
    return previousCard;
}

const Card *Game::getCurrentCard() const {
    vector<const Card *> cardVector = cards[currentSide];
    const Card *currentCard = cardVector[1];
    return currentCard;
}

void Game::setCurrentCard(const Card *card) {
    vector<const Card *> &cardVector = cards[currentSide];
    cardVector.push_back(card);
}

int Game::getNPlayers() const {
    return static_cast<int>(players.size());
}

bool Game::twoCardsSelected() const {
    return (cards[currentSide].size() == 2);
}

void Game::setAllPlayersActive() {
    for (auto &player: players) { player.setActive(true); }
}

void Game::reset(const int &mode) {
    setAllPlayersActive();
    temporaryRevealThreeCards(mode);
    board.reset();
}

void Game::temporaryRevealThreeCards(const int &mode) {
    cout << "Three random cards are revealed temporary in front of the players" << endl;
    const Side sides[4] = {Top, Bottom, Left, Right};
    for (int i = 0; i < getNPlayers(); i++) {
        const Player &player = getPlayer(static_cast<Side>(i));
        cout << player << endl;
        const Side &side = player.getSide();
        switch (side) {
            case Top:
                board.turnFaceUp(A, Two);
                board.turnFaceUp(A, Three);
                board.turnFaceUp(A, Four);
                break;
            case Bottom :
                board.turnFaceUp(E, Two);
                board.turnFaceUp(E, Three);
                board.turnFaceUp(E, Four);
                break;
            case Left:
                board.turnFaceUp(B, One);
                board.turnFaceUp(C, One);
                board.turnFaceUp(D, One);
                break;
            case Right:
                board.turnFaceUp(B, Five);
                board.turnFaceUp(C, Five);
                board.turnFaceUp(D, Five);
                break;
            default:
                break;
        }
    }
    if (mode == 1) {
        cout << (*this) << endl;
    }
    cout << "Cards are hidden now" << endl;
}


int Game::getNActivePlayers() const {
    int activePlayers = 0;
    for (auto player: players) { if (player.isActive()) { activePlayers++; }}
    return activePlayers;
}

void Game::clearSelectedCards() {
    vector<const Card *> &cardVector = cards[currentSide];
    cardVector.pop_back();
    cardVector.pop_back();
}

void Game::awardActivePlayers() {
    for (auto player: players) {
        if (player.isActive()) {
            Reward &reward = *rewardDeck.getNext();
            player.addReward(reward);
            cout << "Awarded " << player.getName() << ": " << reward << "!" << endl;
        }
    }
}

void Game::getValidInput(Letter *letter, Number *number) {
    while (true) {
        string input;
        cout << "Pick a card from (A to E) and from (1 to 5): ";
        while (true) {
            cin >> input;
            if (input.length() == 2) break;
            else cout << "Invalid input, please try again: ";
        }
        *letter = static_cast<Letter>(toEnum(input[0]));
        *number = static_cast<Number>(toEnum(input[1]));
        try {
            if (!board.isFaceUp(*letter, *number)) break;
            else cout << "Card is already faced up! " << endl;
        } catch (const std::exception &exc) {
            cout << "Invalid Card Selected, please try again" << endl;
            cerr << exc.what() << endl;
        }
    }
    setCard(*letter, *number, getCard(*letter, *number));
}

void Game::setCard(const Letter &letter, const Number &number, Card *card) {
    board.turnFaceUp(letter, number);
}

Card *Game::getCard(const Letter &letter, const Number &number) {
    Card *selectedCard = board.getCard(letter, number);
    return selectedCard;
}

ostream &operator<<(ostream &os, const Game &game) {
    os << game.board << endl;
    for (auto player: game.players) { os << player << endl; }
    return os;
}