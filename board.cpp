//
// Created by iDarkDuck on 2018-10-19.
//

#include "board.h"

Board::Board() {
    screen = new string[19];
    for (int x = 0; x < 5; x++) {
        faceDownCards[x] = new bool[5];
        for (int y = 0; y < 5; y++) {
            faceDownCards[x][y] = true;
        }
    }
    setScreen();
}

Board::~Board() {
    delete[] screen;
    for (int x = 0; x < 5; x++) {
        delete [] faceDownCards[x];
    }
}

string *Board::getScreen() const {
    return screen;
}

string Board::getScreenRow(int row) const {
    return screen[row];
}

bool *Board::getIsFaceDownCards() const {
    return &faceDownCards[0][0];
}

//TODO call make_CardDeck() function
void Board::setScreen() {

    CardDeck deck;
    CardDeck::make_CardDeck();
    deck.shuffle();

    vector<Card> cards;
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

bool Board::isFaceUp(const Letter &letter, const Number &number) const {
    return !((faceDownCards[getRowIndex(letter)])[getColIndex(number)]);
}

bool Board::isFaceDown(int i, int j) const {
    return faceDownCards[i][j];
}

int Board::getRowIndex(const Letter &letter) const {
    if (letter == A) {
        return 0;
    } else if (letter == B) {
        return 1;
    } else if (letter == C) {
        return 2;
    } else if (letter == D) {
        return 3;
    } else if (letter == E) {
        return 4;
    } else {
        throw out_of_range("Letter is out of range");
    }
}

int Board::getColIndex(const Number &number) const {
    if (number == One) {
        return 0;
    } else if (number == Two) {
        return 1;
    } else if (number == Three) {
        return 2;
    } else if (number == Four) {
        return 3;
    } else if (number == Five) {
        return 4;
    } else {
        throw out_of_range("Number is out of range");
    }
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
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            faceDownCards[x][y] = true;
        }
    }
}

ostream &operator<<(ostream &os, const Board &board) {
    string *screen = board.getScreen();
    int screenRowCounter = 0;
    int letterRowCounter = 0;

    for (int i = 0; i < 19; i++) {
        bool letterRow = (i == 1 || i == 5 || i == 9 || i == 13 || i == 17);
        if (letterRow) {
            os << (char) (A + letterRowCounter) << " ";
            letterRowCounter++;
        } else {
            os << "  ";
        }
        string temp = screen[screenRowCounter];

        bool row1 = (screenRowCounter == 0 || screenRowCounter == 1 || screenRowCounter == 2);
        bool row2 = (screenRowCounter == 4 || screenRowCounter == 5 || screenRowCounter == 6);
        bool row3 = (screenRowCounter == 8 || screenRowCounter == 9 || screenRowCounter == 10);
        bool row4 = (screenRowCounter == 12 || screenRowCounter == 13 || screenRowCounter == 14);
        bool row5 = (screenRowCounter == 16 || screenRowCounter == 17 || screenRowCounter == 18);

        if (row1) {
            for (int j = 0; j < 5; j++) {
                if (board.isFaceDown(0, j)) {
                    temp[0 + 4 * j] = 'z';
                    temp[1 + 4 * j] = 'z';
                    temp[2 + 4 * j] = 'z';
                }
            }
        } else if (row2) {
            for (int j = 0; j < 5; j++) {
                if (board.isFaceDown(1, j)) {
                    temp[0 + 4 * j] = 'z';
                    temp[1 + 4 * j] = 'z';
                    temp[2 + 4 * j] = 'z';
                }
            }
        } else if (row3) {
            for (int j = 0; j < 5; j++) {
                if (board.isFaceDown(2, j)) {
                    temp[0 + 4 * j] = 'z';
                    temp[1 + 4 * j] = 'z';
                    temp[2 + 4 * j] = 'z';
                }
            }

        } else if (row4) {
            for (int j = 0; j < 5; j++) {
                if (board.isFaceDown(3, j)) {
                    temp[0 + 4 * j] = 'z';
                    temp[1 + 4 * j] = 'z';
                    temp[2 + 4 * j] = 'z';
                }
            }
        } else if (row5) {
            for (int j = 0; j < 5; j++) {
                if (board.isFaceDown(4, j)) {
                    temp[0 + 4 * j] = 'z';
                    temp[1 + 4 * j] = 'z';
                    temp[2 + 4 * j] = 'z';
                }
            }

        }
        os << temp << endl;
        screenRowCounter++;
    }
    os << "   " << "1" << "   " << "2" << "   " << "3" << "   " << "4" << "   " << "5" << endl;
    return os;
}

//KEEP IT PLS DO NOT REMOVE
//    int rows[3];
//    Letter currentLetter = A;
//    for (int i = 0; i < 5; i++) {
//        if (letter == (currentLetter + i)) {
//            rows[0] = (0 + 4 * i);
//            rows[1] = (1 + 4 * i);
//            rows[2] = (2 + 4 * i);
//            break;
//        }
//    }
//
//    int cols[3];
//    Number currentNumber = One;
//    for (int i = 0; i < 5; i++) {
//        if (number == (currentNumber + i)) {
//            cols[0] = (0 + 4 * i);
//            cols[1] = (1 + 4 * i);
//            cols[2] = (2 + 4 * i);
//            break;
//        }
//    }
//
//    for (int x = 0; x < 3; x++) {
//        for (int y = 0; y < 3; y++) {
//            (screen[rows[x]])[cols[y]] = 'z';
//        }
//    }


//return (screen[getRowIndex(letter)])[getColIndex(number)] != 'z';


int Board::getStringRowIndex(const Letter &letter) const {
    if (letter == A) {
        return 1;
    } else if (letter == B) {
        return 5;
    } else if (letter == C) {
        return 9;
    } else if (letter == D) {
        return 13;
    } else if (letter == E) {
        return 17;
    } else {
        throw out_of_range("Letter is out of range");
    }
}

int Board::getStringColIndex(const Number &number) const {
    if (number == One) {
        return 1;
    } else if (number == Two) {
        return 5;
    } else if (number == Three) {
        return 9;
    } else if (number == Four) {
        return 13;
    } else if (number == Five) {
        return 17;
    } else {
        throw out_of_range("Number is out of range");
    }
}