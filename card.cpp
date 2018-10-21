#include <iostream>

using namespace std;

#include "card.h"
#include <cmath>


Card::Card(FaceAnimal faceAnimal, FaceBackground faceBackground) {
    _faceAnimal = faceAnimal;
    _faceBackground = faceBackground;
    _color = getColor();
    _animal = getAnimal();
}

int Card::getNRows() const { return _nRows; }


char Card::getAnimal() const {
    char animal;
    if (_faceAnimal == Crab) {
        animal = 'C';
    } else if (_faceAnimal == Penguin) {
        animal = 'P';
    } else if (_faceAnimal == Octopus) {
        animal = 'O';
    } else if (_faceAnimal == Turtle) {
        animal = 'T';
    } else if (_faceAnimal == Walrus) {
        animal = 'W';
    } else {
        animal = '?';
    }
    return animal;
}

char Card::getColor() const {
    char color;
    if (_faceBackground == Red) {
        color = 'r';
    } else if (_faceBackground == Green) {
        color = 'g';
    } else if (_faceBackground == Purple) {
        color = 'p';
    } else if (_faceBackground == Blue) {
        color = 'b';
    } else if (_faceBackground == Yellow) {
        color = 'y';
    } else {
        color = '?';
    }
    return color;
}

ostream &operator<<(ostream &os, const Card &card) {
    for (int row = 0; row < card.getNRows(); ++row) {
        string rowString = card(row);
        cout << rowString << endl;
    }
    return os;
}

string Card::operator()(int row) const {
    string rowString{_color, _color, _color};
    if (row == ceil(getNRows() / 2)) {
        rowString[1] = _animal;
    }
    return rowString;
}

