//
// Created by iDarkDuck on 2018-10-19.
//

#include "board.h"
#include "card.h"

//returns true if the card at a given position is
//face up. Letter and Number are enumerations. Throws an exception of type OutOfRange if an invalid
//Letter and Number combination was given.

bool Board::isFaceUp(const Letter &letter, const Number &number) const {

//    if (letter == 'Z') {
//        return false;
//    } else if (number < 1 || number > 5) {
//        throw out_of_range("Number is out of range");
//        return false;
//    } else {
//        if (letter == Crab) {
//            return true;
//        } else if (letter == Penguin) {
//            return true;
//        } else if (letter == Octopus) {
//            return true;
//        } else if (letter == Turtle) {
//            return true;
//        } else if (letter == Walrus) {
//            return true;
//        }
//        throw out_of_range("Letter is out of range");
//    }
    return false;
}


//changes the state of the specified card return false
//if card was up already. Throws an exception of type OutOfRange if an invalid Letter and Number
//combination was given.
bool Board::turnFaceUp(const Letter &, const Number &) {
    return false;
}


//changes the state of the specified card return
//false if card was down already. Throws an exception of type OutOfRange if an invalid Letter and
//        Number combination was given.
bool Board::turnFaceDown(const Letter &, const Number &) {
    return false;
}

//changes the state to all cards to be face down
void Board::reset() {

}

//A board must be printable with the insertion operator cout << board
ostream &operator<<(ostream &os, const Board &player) {

}