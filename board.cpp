//
// Created by iDarkDuck on 2018-10-19.
//

#include "board.h"

Board::Board() {
    screen = new string[19];
    for (auto &faceDownCard : faceDownCards) {
        faceDownCard = new bool[5];
        for (int y = 0; y < 5; y++) { faceDownCard[y] = true; }
    }
}

Board::Board(const Board &board) : cards(board.cards), cards2D(board.cards2D) {
    screen = new string[19];
    for (int i = 0; i < 19; i++) screen[i] = board.screen[i];
    for (auto &faceDownCard : faceDownCards) {
        faceDownCard = new bool[5];
        for (int y = 0; y < 5; y++)faceDownCard[y] = true;
    }
    for (int i = 0; i < 5; i++) { for (int j = 0; j < 5; j++) { faceDownCards[i][j] = board.faceDownCards[i][j]; }}
}

Board::~Board() {
    delete[] screen;
    for (auto &faceDownCard : faceDownCards) delete[] faceDownCard;
    for (auto &cardVector : cards2D) delete cardVector;
    for (auto &card : cards) delete card;
}

void Board::setCard(const Letter &letter, const Number &number, Card *card) {
    cards.push_back(card);
    if (cards.size() == 25) setScreen();
}

void Board::setScreen() {
    for (int i = 0; i < 25; i = i + 5) {
        auto *cardVector = new vector<Card *>;
        for (int j = 0; j < 5; j++) { cardVector->push_back(cards[i + j]); }
        cards2D.push_back(cardVector);
    }
    int screenRowCounter = 0;
    for (int i = 0; i < 25; i = i + 5) {
        for (int j = 0; j < 3; j++) {
            screen[screenRowCounter++] =
                    (*cards[i])(j) + " " + (*cards[i + 1])(j) + " " +
                    (*cards[i + 2])(j) + " " + (*cards[i + 3])(j) + " " + (*cards[i + 4])(j);
        }
        screenRowCounter++;
    }
}

string *Board::getScreen() const { return screen; }

bool Board::isValidCard(const Letter &letter, const Number &number) const {
    if (getIndex(letter, "Letter") == 2 && getIndex(number, "Number") == 2)
        throw out_of_range("Not allowed to pick treasure card!");
    return true;
}

bool Board::isFaceUp(const Letter &letter, const Number &number) const {
    if (getIndex(letter, "Letter") == 2 && getIndex(number, "Number") == 2)
        throw out_of_range("Not allowed to pick treasure card!");
    return !((faceDownCards[getIndex(letter, "Letter")])[getIndex(number, "Number")]);
}

bool Board::isFaceDown(const int &i, const int &j) const { return faceDownCards[i][j]; }

int Board::getIndex(const int &input, const string &typeEnum) const {
    switch (input) {
        case A:
            return 0;
        case B:
            return 1;
        case C:
            return 2;
        case D:
            return 3;
        case E:
            return 4;
        default:
            throw out_of_range(typeEnum + " is out of range");
    }
}

Card *Board::getCard(const Letter &letter, const Number &number) {
    return (*cards2D[getIndex(letter, "Letter")])[getIndex(number, "Number")];
}

bool Board::turnFaceUp(const Letter &letter, const Number &number) {
    if (isFaceUp(letter, number)) return false;
    return !(faceDownCards[getIndex(letter, "Letter")][getIndex(number, "Number")] = false);
}

bool Board::turnFaceDown(const Letter &letter, const Number &number) {
    if (!isFaceUp(letter, number)) return false;
    return (faceDownCards[getIndex(letter, "Letter")][getIndex(number, "Number")] = true);
}

void Board::reset() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (i == 3 && j == 3) continue;
            turnFaceDown(static_cast<Letter>(i), static_cast<Number>(j));
        }
    }
}

ostream &operator<<(ostream &os, const Board &board) {
    string *screen = board.getScreen();
    int screenRowCounter = 0, letterRowCounter = 0;
    for (int i = 0; i < 19; i++) {
        bool letterRow = (i == 1 || i == 5 || i == 9 || i == 13 || i == 17);
        if (letterRow) os << (char) ('A' + letterRowCounter++) << " ";
        else os << "  ";
        string temp = screen[screenRowCounter];
        for (int row = 0; row <= 16; row = row + 4) {
            if (screenRowCounter >= (0 + row) && screenRowCounter <= (2 + row)) {
                for (int j = 0; j < 5; j++)
                    if (board.isFaceDown((row / 4), j)) temp[0 + 4 * j] = temp[1 + 4 * j] = temp[2 + 4 * j] = 'z';
                if ((row / 4) == 2) { temp[8] = temp[9] = temp[10] = ' '; };
            }
        }
        os << temp << endl;
        screenRowCounter++;
    }
    return (os << "   " << "1" << "   " << "2" << "   " << "3" << "   " << "4" << "   " << "5" << endl);
}

void Board::swapCards(const Letter &l1, const Number &n1, const Letter &l2, const Number &n2) {
    // Card *card1 = (*cards2D[getIndex(l1, "Letter")])[getIndex(n1, "Number")];
    Card *card2 = (*cards2D[getIndex(l2, "Letter")])[getIndex(n2, "Number")];
    //cout << "BEFORE SWAP CARDS" << endl;
    //cout << *(*cards2D[getIndex(l1, "Letter")])[getIndex(n1, "Number")] << endl;
    //cout << *(*cards2D[getIndex(l2, "Letter")])[getIndex(n2, "Number")] << endl;
    Card *tempCard = (*cards2D[getIndex(l1, "Letter")])[getIndex(n1, "Number")];
    (*cards2D[getIndex(l1, "Letter")])[getIndex(n1, "Number")] = card2;
    (*cards2D[getIndex(l2, "Letter")])[getIndex(n2, "Number")] = tempCard;
    //cout << "AFTER SWAP CARDS" << endl << *card1 << *card2 << endl;
    //cout << *(*cards2D[getIndex(l1, "Letter")])[getIndex(n1, "Number")] << endl;
    //cout << *(*cards2D[getIndex(l2, "Letter")])[getIndex(n2, "Number")] << endl;
    bool &first = faceDownCards[getIndex(l1, "Letter")][getIndex(n1, "Number")];
    bool &second = faceDownCards[getIndex(l2, "Letter")][getIndex(n2, "Number")];
    //cout << "BEFORE: " << first << endl;
    //cout << "BEFORE: " << second << endl;
    bool temp = first;
    first = second;
    second = temp;
    //cout << "AFTER: " << first << endl;
    //cout << "AFTER: " << second << endl;
}