//
// Created by iDarkDuck on 2018-10-19.
//

#include "player.h"


//return the name of the player.
string Player::getName() const {
    return "sjndakjs";
}

//set the status of the player as active or inactive.
void Player::setActive(bool) {
}

//returns true if the player is active.
bool Player::isActive() {
    return false;
}

//return the number of rubies won by this player.
int Player::getNRubies() const {
    return 0;
}

//add a reward with a given number of rubies.
void Player::addReward(const Reward &) {
    //return NULL;
}

//add a reward with a given number of rubies.
void Player::setDisplayMode(bool endOfGame) {

}

//A player must be printable with the insertion operator cout << player. An example print out with
//        endOfGame false could look as follows:
//Joe Remember Doe: left (active)
//Once endOfGame is true:
//Joe Remember Doe: 3 rubies
void Player::print(){

}
