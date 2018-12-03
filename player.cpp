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

bool operator!=(const Player &l, const Player &r) { return l.getName() != r.getName(); }

string Player::getSideToString() const {
    if (side == Side::Top) return "top";
    else if (side == Side::Bottom) return "bottom";
    else if (side == Side::Right) return "right";
    else return "left";
}

#ifdef TEST_PLAYER
#if 0

int main() {
    cout << "TEST_PLAYER" << endl;
    Player p = Player("Peter");
    p.setSide(Side::Top);
    cout << "Printing player start of the game " << endl;
    cout << p << endl;
    assert("Peter" == p.getName());
    assert(p.getSide() == Side::Top);
    assert(p.isActive() == true);
    assert(p.getNRubies() == 0);
    RewardDeck &r = RewardDeck::make_RewardDeck();
    Reward *reward = r.getNext();
    p.addReward(*reward);
    assert(p.getNRubies() == reward->getNRubies());
    p.setActive(false);
    assert(p.isActive() == false);
    p.setDisplayMode(true);
    cout << "Printing player end of the game " << endl;
    cout << p << endl;
    Player p1 = Player("Nevin");
    assert(p > p1);
    assert(p1 < p);
    assert(p == p);
    assert(p != p1);
    Player p2 = Player("Peter");
    assert(p == p2);
    cout << "Testing Completed" << endl;
}

#endif
#endif // TEST_PLAYER