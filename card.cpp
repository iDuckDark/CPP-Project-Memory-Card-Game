//
// Created by iDarkDuck on 2018-10-19.
//


#include "card.h"


//Card c(Penguin,Red); // This constructor will be private
//for (int row = 0; row <c.getNRows(); ++row ) {
//std::string rowString = c(row);
//std::cout << rowString << std::endl;
//}
//Note that Penguin and Red are enumeration values of type FaceAnimal and FaceBackground.

Card::Card(FaceAnimal faceAnimal, FaceBackground faceBackground) : faceAnimal(faceAnimal), faceBackground(faceBackground){

}

string Card::card(int row){
    return to_string(row);
}

int Card::getNRows() const{
    return nRows;
}


ostream &operator<<(ostream &os, const Card &card) {

//    for (int row = 0; row < card.getNRows(); ++row) {
//        string rowString = card(row);
//        cout << rowString << std::endl;
//    }
    //os << player.getName() << " Remember Doe: left" << "(" << player.active << ")" << endl;
    return os;
}