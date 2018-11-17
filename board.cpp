//
// Created by iDarkDuck on 2018-10-19.
//

#include "board.h"

Board::Board() {
    screen = new string[19];
    for (auto &faceDownCard : faceDownCards) {
        faceDownCard = new bool[5];
        for (int y = 0; y < 5; y++) {
            faceDownCard[y] = true;
        }
    }
    setScreen();
}

Board::~Board() {
    delete[] screen;
    for (auto &faceDownCard : faceDownCards) {
        delete[] faceDownCard;
    }
    for (auto &cardVector : cards2D) {
        delete cardVector;
    }
}

string *Board::getScreen() const {
    return screen;
}

void Board::setScreen() {
    CardDeck &deck = CardDeck::make_CardDeck();
    for (int i = 0; i < 25; i++) { cards.push_back(*deck.getNext()); }
    for (int i = 0; i < 25; i = i + 5) {
        auto *cardVector = new vector<Card *>;
        for (int j = 0; j < 5; j++) { cardVector->push_back(&cards[i + j]); }
        cards2D.push_back(cardVector);
    }

    int screenRowCounter = 0;
    for (int i = 0; i < 25; i = i + 5) {
        for (int j = 0; j < 3; j++) {
            string row =
                    (cards[i])(j) + " " + (cards[i + 1])(j) + " " + (cards[i + 2])(j) + " " + (cards[i + 3])(j) + " " +
                    (cards[i + 4])(j);
            screen[screenRowCounter++] = row;
        }
        screenRowCounter++;
    }
}

bool Board::isFaceUp(const Letter &letter, const Number &number) const {
    return !((faceDownCards[getIndex(letter, "Letter")])[getIndex(number, "Number")]);
}

bool Board::isFaceDown(const int &i, const int &j) const {
    return faceDownCards[i][j];
}

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
    if (isFaceUp(letter, number)) {
        return false;
    }
    char rows[] = {A, B, C, D, E};
    char cols[] = {One, Two, Three, Four, Five};

    int selectedRow = 0, selectedCol = 0;
    for (int i = 0; i < 5; i++) {
        if (rows[i] == letter) {
            selectedRow = i;
        }
        if (cols[i] == number) {
            selectedCol = i;
        }
    }
    faceDownCards[selectedRow][selectedCol] = false;
    return true;
}


bool Board::turnFaceDown(const Letter &letter, const Number &number) {
    if (!isFaceUp(letter, number)) {
        return false;
    }
    char rows[] = {A, B, C, D, E};
    char cols[] = {One, Two, Three, Four, Five};

    int selectedRow = 0, selectedCol = 0;
    for (int i = 0; i < 5; i++) {
        if (rows[i] == letter) {
            selectedRow = i;
        }
        if (cols[i] == number) {
            selectedCol = i;
        }
    }
    faceDownCards[selectedRow][selectedCol] = true;
    return true;
}


void Board::reset() {
    for (auto &faceDownCard : faceDownCards) {
        for (int y = 0; y < 5; y++) {
            faceDownCard[y] = true;
        }
    }
}

ostream &operator<<(ostream &os, const Board &board) {
    string *screen = board.getScreen();
    int screenRowCounter = 0;
    int letterRowCounter = 0;

    for (int i = 0; i < 19; i++) {
        bool letterRow = (i == 1 || i == 5 || i == 9 || i == 13 || i == 17);
        if (letterRow) os << (char) ('A' + letterRowCounter++) << " ";
        else os << "  ";

        string temp = screen[screenRowCounter];
        bool row1 = (screenRowCounter == 0 || screenRowCounter == 1 || screenRowCounter == 2);
        bool row2 = (screenRowCounter == 4 || screenRowCounter == 5 || screenRowCounter == 6);
        bool row3 = (screenRowCounter == 8 || screenRowCounter == 9 || screenRowCounter == 10);
        bool row4 = (screenRowCounter == 12 || screenRowCounter == 13 || screenRowCounter == 14);
        bool row5 = (screenRowCounter == 16 || screenRowCounter == 17 || screenRowCounter == 18);

        if (row1) {
            for (int j = 0; j < 5; j++) {
                if (board.isFaceDown(0, j)) {
                    temp[0 + 4 * j] = temp[1 + 4 * j] = temp[2 + 4 * j] = 'z';
                }
            }
        } else if (row2) {
            for (int j = 0; j < 5; j++) {
                if (board.isFaceDown(1, j)) {
                    temp[0 + 4 * j] = temp[1 + 4 * j] = temp[2 + 4 * j] = 'z';
                }
            }
        } else if (row3) {
            for (int j = 0; j < 5; j++) {
                if (board.isFaceDown(2, j)) {
                    temp[0 + 4 * j] = temp[1 + 4 * j] = temp[2 + 4 * j] = 'z';
                }
            }
            temp[8] = temp[9] = temp[10] = ' ';
        } else if (row4) {
            for (int j = 0; j < 5; j++) {
                if (board.isFaceDown(3, j)) {
                    temp[0 + 4 * j] = temp[1 + 4 * j] = temp[2 + 4 * j] = 'z';
                }
            }
        } else if (row5) {
            for (int j = 0; j < 5; j++) {
                if (board.isFaceDown(4, j)) {
                    temp[0 + 4 * j] = temp[1 + 4 * j] = temp[2 + 4 * j] = 'z';
                }
            }
        }
        os << temp << endl;
        screenRowCounter++;
    }
    os << "   " << "1" << "   " << "2" << "   " << "3" << "   " << "4" << "   " << "5" << endl;
    return os;
}

int toEnum(const char input) {
    switch (input) {
        case 'A':
        case '1':
            return 1;
        case 'B':
        case '2':
            return 2;
        case 'C':
        case '3':
            return 3;
        case 'D':
        case '4':
            return 4;
        case 'E':
        case '5':
            return 5;
        default:
            return -1;
    }
}