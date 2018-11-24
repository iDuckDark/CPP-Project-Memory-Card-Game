//
// Created by iDarkDuck on 2018-10-19.
//

#include "player.h"

Player::Player(const string &name) : name(name), nRubies(0), active(true), endOfGame(false), side(Side::Top) {}

string Player::getName() const { return name; }

void Player::setActive(bool active) { this->active = active; }

bool Player::isActive() { return active; }

int Player::getNRubies() const { return nRubies; }

void Player::addReward(const Reward &reward) {
    nRubies += reward.getNRubies(), cout << "Awarded " << getName() << ": " << reward << "!" << endl;
}

void Player::setDisplayMode(bool endOfGame) { this->endOfGame = endOfGame; }

Side Player::getSide() const { return side; }

void Player::setSide(Side side) { this->side = side; }

ostream &operator<<(ostream &os, const Player &player) {
    os << player.getName() << ": ";
    if (!player.endOfGame)
        return (os << player.getSideToString() << " (" << (player.active ? "active" : "inactive") << ")" << endl);
    return (os << " " << player.getNRubies() << " rubies" << endl);
}

bool operator<(const Player &lhs, const Player &rhs) { return lhs.getNRubies() < rhs.getNRubies(); }

bool operator>(const Player &lhs, const Player &rhs) { return lhs.getNRubies() > rhs.getNRubies(); }

bool operator==(const Player &l, const Player &r) { return l.getName() == r.getName(); }

string Player::getSideToString() const {
    switch (side) {
        case Side::Top:
            return "top";
        case Side::Bottom:
            return "bottom";
        case Side::Right:
            return "right";
        default:
            return "left";
    }
}