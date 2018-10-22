#include <iostream>
#include "player.h"
#include "card.h"
#include "board.h"

using namespace std;

int main() {

//    Player *p = new Player{"Peter", "top", 2};
//    cout << *p << endl;
//    p->setDisplayMode(true);
//    cout << *p << endl;

    Board board;
    board.setScreen();

    cout << board << endl;

    //cout << board.isFaceUp(A, One) << endl;

    //board.turnFaceDown(A, One);

    board.turnFaceUp(A, Two);

    cout << board << endl;

    cout << board.isFaceUp(A,Two) << endl;

    board.reset();

    cout << board << endl;
    cout << "No Errors" << endl;

//    static CardDeck* cardDeck = &CardDeck::make_CardDeck();

    return 0;
}
