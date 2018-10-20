#include <iostream>
using namespace std;
#include "card.h"
#include <math.h>


Card::Card(FaceAnimal faceAnimal, FaceBackground faceBackground) {
    _faceAnimal=faceAnimal;
    _faceBackground = faceBackground;
    _color = getColor();
    _animal = getAnimal();
}

int Card::getNRows() const {return _nRows;}

string Card::getRow(int row) {
    string blanks(" ",3);
    //has 3 columns so a string of size 3
    return blanks;
}


char Card::getAnimal() const {
    char animal='?';
    if(_faceAnimal==Crab){
        animal='C';
    }else if(_faceAnimal==Penguin){
        animal='P';
    }else if(_faceAnimal==Octopus){
        animal='O';
    }else if(_faceAnimal==Turtle){
        animal='T';
    }else if(_faceAnimal==Walrus){
        animal='W';
    }else{
        animal='?';
    }
    return  animal;
}

char Card::getColor() const {
    char color = '?';
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
//string Card::Card(int row) {
//    return to_string(row);
//}



ostream &operator<<(ostream &os, const Card &card) {

//    for (int row = 0; row < card.getNRows(); ++row) {
//        string rowString = card(row);
//        cout << rowString << std::endl;
//    }
    //os << player.getName() << " Remember Doe: left" << "(" << player.active << ")" << endl;
    return os;
}

