//
// Created by iDarkDuck on 2018-10-19.
//

#include "board.h"

//returns true if the card at a given position is
//face up. Letter and Number are enumerations. Throws an exception of type OutOfRange if an invalid
//Letter and Number combination was given.

bool Board::isFaceUp(const char &Letter, const int &Number) const {
    return false;
}


//changes the state of the specified card return false
//if card was up already. Throws an exception of type OutOfRange if an invalid Letter and Number
//combination was given.
bool Board::turnFaceUp(const char &Letter, const int &Number) {
    return false;
}


//changes the state of the specified card return
//false if card was down already. Throws an exception of type OutOfRange if an invalid Letter and
//        Number combination was given.
bool Board::turnFaceDown(const char &Letter, const int &Number) {
    return false;
}

//changes the state to all cards to be face down
void Board::reset() {

}

//A board must be printable with the insertion operator cout << board
void Board::print() {

}