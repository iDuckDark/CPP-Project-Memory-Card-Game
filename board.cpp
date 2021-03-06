//
// Created by iDarkDuck on 2018-10-19.
//

#include "board.h"

//#define TEST_BOARD

int Board::singleton = false;

Board::Board() : l1(Z), n1(Zero) {
    (singleton) ? throw NoMoreCardsException() : singleton = true;
    screen = new string[19];
    for (auto &faceDownCard : faceDownCards) {
        faceDownCard = new bool[5];
        for (int y = 0; y < 5; y++) { faceDownCard[y] = true; }
    }
    if (ready && cards2D.empty()) throw out_of_range("NoMoreCards");
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
    if (cards2D.size() == 0) throw out_of_range("NoMoreCards");
    ready = true;
}

string *Board::getScreen() const { return screen; }

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

void Board::setCard(const Letter &letter, const Number &number, Card *card) {
    if (!ready) cards.push_back(card);
    if (cards.size() == 25 && !ready) setScreen();
    else if (ready) {
        if (l1 == Z || n1 == Zero) { l1 = letter, n1 = number; }
        else { swapCards(l1, n1, letter, number); }
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
    Card *card2 = (*cards2D[getIndex(l2, "Letter")])[getIndex(n2, "Number")];
    Card *tempCard = (*cards2D[getIndex(l1, "Letter")])[getIndex(n1, "Number")];
    (*cards2D[getIndex(l1, "Letter")])[getIndex(n1, "Number")] = card2;
    (*cards2D[getIndex(l2, "Letter")])[getIndex(n2, "Number")] = tempCard;
    bool &first = faceDownCards[getIndex(l1, "Letter")][getIndex(n1, "Number")];
    bool &second = faceDownCards[getIndex(l2, "Letter")][getIndex(n2, "Number")];
    bool temp = first;
    first = second;
    second = temp;
    this->l1 = Z, this->n1 = Zero;
}

#ifdef TEST_BOARD

int main() {
    cout << "TEST_BOARD" << endl;
    Board board;
    CardDeck &deck = CardDeck::make_CardDeck();
    int i = 1, j = 1;
    while (!deck.isEmpty()) {
        board.setCard(static_cast<Letter>(i), static_cast<Number>(j++), deck.getNext());
        if (j == 5) { j = 0, i++; }
    }
    cout << "PRINTING BOARD DEFAULT ALL FACE DOWN" << endl;
    cout << board << endl;
    cout << "Turning Card C1 & C4 face UP" << endl;
    assert(board.turnFaceUp(C, One) == true);
    assert(board.turnFaceUp(C, Four) == true);
    cout << board << endl;
    //Attempting to face up again
    assert(board.turnFaceUp(C, One) == false);
    assert(board.turnFaceUp(C, Four) == false);
    cout << "Turning Card C1 & C4 face DOWN" << endl;
    assert(board.turnFaceDown(C, One) == true);
    assert(board.turnFaceDown(C, Four) == true);
    cout << board << endl;
    //Attempting to face down again
    assert(board.turnFaceDown(C, One) == false);
    assert(board.turnFaceDown(C, Four) == false);
    //Attempting to pick the treasure card, which is not allowed
    bool treasureCard;
    try { treasureCard = board.turnFaceUp(C, Three); }
    catch (...) { treasureCard = false; }
    assert(treasureCard == false);
    //Check if it's face up and getting card
    assert(board.isFaceUp(E, Two) == false);
    assert(board.turnFaceUp(E, Two) == true);
    assert(board.isFaceUp(E, Two) == true);
    assert(board.getCard(E, Two) != nullptr);
    Card *ptr;
    try { ptr = board.getCard(E, Zero); }
    catch (...) { ptr = nullptr; }
    assert(ptr == nullptr);
    cout << board << endl;
    cout << "Reseting the board" << endl;
    board.reset();
    cout << board << endl;
    cout << "Test making another board" << endl;
    bool makeBoard2;
    try {
        Board board2;
        makeBoard2 = true;
    }
    catch (const exception &exc) {
        cout << exc.what() << endl;
        makeBoard2 = false;
    }
    assert(cout << (makeBoard2 == false) << endl);
    cout << "Testing Completed" << endl;
}

#endif