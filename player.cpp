//
// Created by iDarkDuck on 2018-10-19.
//

#include "player.h"

Player::Player(string name, string sideOfTheBoard, int nRubies) : name(name), sideOfTheBoard(sideOfTheBoard),
                                                                  nRubies(nRubies) {
    this->active = true;
    this->endOfGame = false;
}

string Player::getName() const {
    return name;
}

void Player::setActive(bool active) {
    this->active = active;
}

bool Player::isActive() {
    return active;
}

int Player::getNRubies() const {
    return nRubies;
}

void Player::addReward(const Reward &reward) {
    rewards.push_back(reward);
}

void Player::setDisplayMode(bool endOfGame) {
    this->endOfGame = endOfGame;
}

ostream &operator<<(ostream &os, const Player &player) {
    if (player.getEndOfGame()) {
        string status = player.active ? "active" : "inactive";
        os << player.getName() << player.getSideOfTheBoard() << "(" << status << ")"
           << endl;
    } else {
        os << player.getName() << " " << player.getSideOfTheBoard() << " " << player.getNRubies()
           << " rubies" << endl;
    }
    return os;
}

//Added Own Functions
bool Player::getEndOfGame() const {
    return this->endOfGame;
}

string Player::getSideOfTheBoard() const {
    return this->sideOfTheBoard;
}