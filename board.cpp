//
// Created by iDarkDuck on 2018-10-19.
//

#include "board.h"
#include "card.h"

Board::Board() {
    screen = new string[19];
}

Board::~Board() {
    delete[] screen;
}

string *Board::getScreen() const {
    return screen;
}

//TODO call make_CardDeck() function
void Board::setScreen() {
    CardDeck deck;
    //CardDeck cardDeck = CardDeck::make_CardDeck();
    vector<Card> cards;
    deck.shuffle();

    for (int i = 0; i < 25; i++) {
        cards.push_back(*deck.getNext());
    }
    int screenRowCounter = 0;
    for (int i = 0; i < 25; i = i + 5) {
        for (int j = 0; j < 3; j++) {
            string row = cards[i](j) + " " + cards[i + 1](j) + " " + cards[i + 2](j) + " " + cards[i + 3](j) + " " +
                         cards[i + 4](j);
            screen[screenRowCounter] = row;
            screenRowCounter++;
        }
        screenRowCounter++;
    }
}

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
ostream &operator<<(ostream &os, const Board &board) {

    string *screen = board.getScreen();
    int screenRowCounter2 = 0;
    int letterRowCounter = 0;

    for (int i = 0; i < 20; i++) {
        bool letterRow = (i == 1 || i == 5 || i == 9 || i == 13 || i == 17);
        if (letterRow) {
            os << (char) (A + letterRowCounter) << " ";
            letterRowCounter++;
        } else {
            os << "  ";
        }
        os << screen[screenRowCounter2] << endl;
        screenRowCounter2++;
    }
    os << "   " << "1" << "   " << "2" << "   " << "3" << "   " << "4" << "   " << "5" << endl;
    return os;
}