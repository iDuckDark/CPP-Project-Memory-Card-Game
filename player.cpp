//
// Created by iDarkDuck on 2018-10-19.
//

#include "player.h"

Player::Player(string name) : name(name), nRubies(0), active(true), endOfGame(false) {}

string Player::getName() const { return name; }

void Player::setActive(bool active) { this->active = active; }

bool Player::isActive() { return active; }

int Player::getNRubies() const { return nRubies; }

void Player::addReward(const Reward &reward) { nRubies += reward.getNRubies(); }

void Player::setDisplayMode(bool endOfGame) { this->endOfGame = endOfGame; }

Side Player::getSide() const {
    return side;
}

void Player::setSide(Side side) { this->side = side; }

string sideToString(Side side) {
    switch (side) {
        case Top:
            return "Top";
        case Bottom:
            return "Bottom";
        case Right:
            return "Right";
        default:
            return "Left";
    }
}

ostream &operator<<(ostream &os, const Player &player) {
    os << player.getName() << ": " << player.getSide();
    if (!player.endOfGame) {
        os << " (" << (player.active ? "active" : "inactive") << ")" << endl;
    } else {
        os << " " << player.getNRubies() << " rubies" << endl;
    }
    return os;
}


bool operator<(const Player &lhs, const Player &rhs) { return lhs.getNRubies() < rhs.getNRubies(); }

bool operator>(const Player &lhs, const Player &rhs) { return lhs.getNRubies() > rhs.getNRubies(); }

bool operator==(const Player &lhs, const Player &rhs) { return lhs.getNRubies() == rhs.getNRubies(); }