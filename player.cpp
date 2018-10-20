//
// Created by iDarkDuck on 2018-10-19.
//

#include "player.h"

Player::Player(string name, string sideOfTheBoard, int nRubies) : name(name), sideOfTheBoard(sideOfTheBoard),
                                                                  nRubies(nRubies) {
    //Initialize Reward Vector?;
    this->active = true;
    this->endOfGame = false;
}

//return the name of the player.
string Player::getName() const {
    return name;
}

//set the status of the player as active or inactive.
void Player::setActive(bool active) {
    this->active = active;
}

//returns true if the player is active.
//TO-ASK MUST ADD CONST TO AVOID ERRORS?
bool Player::isActive() {
    return active;
}

//return the number of rubies won by this player.
int Player::getNRubies() const {
    return nRubies;
}

//add a reward with a given number of rubies.
void Player::addReward(const Reward &reward) {
    rewards.push_back(reward);
}

//add a reward with a given number of rubies.
void Player::setDisplayMode(bool endOfGame) {
    this->endOfGame = true;
}


//A player must be printable with the insertion operator cout << player. An example print out with
//endOfGame false could look as follows:
//Joe Remember Doe: left (active)
//Once endOfGame is true:
//Joe Remember Doe: 3 rubies
ostream &operator<<(ostream &os, const Player &player) {
    if (player.getEndOfGame()) {
        string status = player.active? "active" : "inactive";
        os << player.getName() << " Remember Doe: " << player.getSideOfTheBoard() << "(" << status << ")"
           << endl;
    } else {
        os << player.getName() << " Remember Doe: " << player.getSideOfTheBoard() << " " << player.getNRubies()
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