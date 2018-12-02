//
// Created by iDarkDuck on 2018-10-19.
//
#define TEST_PLAYER
#include "player.h"

Player::Player(const string &name) : name(name), nRubies(0), active(true), endOfGame(false), side(Side::Top) {}

string Player::getName() const { return name; }

void Player::setActive(const bool &active) { this->active = active; }

bool Player::isActive() const { return active; }

int Player::getNRubies() const { return nRubies; }

void Player::addReward(const Reward &reward) {
    nRubies += reward.getNRubies(), cout << "Awarded " << getName() << ": " << reward << "!" << endl;
}

void Player::setDisplayMode(const bool &endOfGame) { this->endOfGame = endOfGame; }

Side Player::getSide() const { return side; }

void Player::setSide(const Side &side) { this->side = side; }

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
    if (side == Side::Top) return "top";
    else if (side == Side::Bottom) return "bottom";
    else if (side == Side::Right) return "right";
    else return "left";
}

#ifdef TEST_PLAYER
#if 0
int main() {
    cout<<"TEST_PLAYER"<<endl;
    Player p = Player("Peter");
    cout << p.getName() << endl;
    cout << p << endl;
}
#endif
#endif // TEST_PLAYER