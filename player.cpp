//
// Created by iDarkDuck on 2018-10-19.
//

#include "player.h"

Player::Player(string name, string sideOfTheBoard, int nRubies) : name(name), sideOfTheBoard(sideOfTheBoard),
                                                                  nRubies(nRubies) {
    active = true;
    endOfGame = false;
}

string Player::getName() const {
    return name;
}

void Player::setActive(bool act) {
    active = act;
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
    if (!player.endOfGame) {
        string status = player.active ? "active" : "inactive";
        os << player.getName() << ": " << player.getSideOfTheBoard() << " (" << status << ")"
           << endl;
    } else {
        os << player.getName() << " " << player.getSideOfTheBoard() << " " << player.getNRubies()
           << " rubies" << endl;
    }
    return os;
}

bool operator<(const Player &lhs, const Player &rhs) {
    return lhs.getNRubies() < rhs.getNRubies();
}

bool operator>(const Player &lhs, const Player &rhs) {
    return lhs.getNRubies() > rhs.getNRubies();
}

bool operator==(const Player &lhs, const Player &rhs) {
    return lhs.getNRubies() == rhs.getNRubies();
}

//Added Own Functions

string Player::getSideOfTheBoard() const {
    return this->sideOfTheBoard;
}