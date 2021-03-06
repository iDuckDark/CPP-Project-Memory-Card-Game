#include "card.h"
#include "carddeck.h"
#include <cassert>

//#define TEST_CARD

Card::Card(const FaceAnimal &faceAnimal, const FaceBackground &faceBackground) :
        _faceAnimal(faceAnimal),
        _faceBackground(faceBackground),
        _color(getColor()),
        _animal(getAnimal()) {
}

Card::Card(const Card &card) :
        _faceAnimal(card._faceAnimal),
        _faceBackground(card._faceBackground),
        _color(card.getColor()),
        _animal(card.getAnimal()) {
}

Card &Card::operator=(const Card &card) {
    if (this != &card) {
        _faceAnimal = (card._faceAnimal);
        _faceBackground = (card._faceBackground);
        _color = (card.getColor());
        _animal = (card.getAnimal());
    }
    return (*this);
}

Card::operator FaceBackground() { return _faceBackground; }

Card::operator FaceAnimal() { return _faceAnimal; }

int Card::getNRows() const { return _nRows; }

char Card::getAnimal() const {
    switch (_faceAnimal) {
        case Crab:
            return 'C';
        case Penguin:
            return 'P';
        case Octopus:
            return 'O';
        case Turtle:
            return 'T';
        case Walrus:
            return 'W';
        default:
            throw out_of_range("FaceAnimal is out of range");
    }
}

char Card::getColor() const {
    switch (_faceBackground) {
        case static_cast<FaceBackground>(Crab):
            return 'r';
        case static_cast<FaceBackground>(Penguin):
            return 'g';
        case static_cast<FaceBackground>(Octopus):
            return 'p';
        case static_cast<FaceBackground>(Turtle):
            return 'b';
        case static_cast<FaceBackground>(Walrus):
            return 'y';
        default:
            throw out_of_range("FaceBackground is out of range");
    }
}

ostream &operator<<(ostream &os, const Card &card) {
    for (int row = 0; row < card.getNRows(); ++row) os << card(row) << endl;
    return os;
}

string Card::operator()(const int &row) const {
    string rowString{_color, _color, _color};
    if (row == ceil(getNRows() / 2)) rowString[1] = _animal;
    return rowString;
}

bool operator==(const Card &lhs, const Card &rhs) {
    return (lhs.getAnimal() == rhs.getAnimal()) || (lhs.getColor() == rhs.getColor());
}


#ifdef TEST_CARD

int main() {
    cout << "TEST_CARD" << endl;
    CardDeck &c = CardDeck::make_CardDeck();
    Card *card = c.getNext();
    Card *card2 = c.getNext();
    cout << *card << endl;
    cout << *card2 << endl;
    cout << "Animal " << card->getAnimal() << endl;
    cout << "Colour " << card->getColor() << endl;
    assert(*card == *card);
    cout << "Testing Completed" << endl;
}

#endif
