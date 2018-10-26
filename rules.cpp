//
// Created by iDarkDuck on 2018-10-19.
//

#include "rules.h"


bool Rules::isValid(const Game &game) {
    cout << "TEST RULES IS VALID?" << endl;
    if (game.twoCardsSelected()) {
        cout << "Previous card" << endl << *game.getPreviousCard() << endl;
        cout << "Next card" << endl << *game.getCurrentCard() << endl;
        if (game.getPreviousCard() == game.getCurrentCard()) {
            return true;
        } else {
            return false;
        }
    }
    cout << "NO TWO CARDS SELECTED" << endl;
    return false;
}

bool Rules::gameOver(const Game &game) {
    //cout << "GAME OVER ? " << game.getRound() << endl;
    return game.getRound() >= 7;
}

bool Rules::roundOver(const Game &game) {
    return game.getNActivePlayers() == 1;
}


void Rules::expertRules(Card* card,const Game &game,Letter letter, Number number){
    if (card->getAnimal()== 'O'){
        expertOctopus(card,game,letter,number);
    }else if (card->getAnimal()== 'P'){
        expertPenguin(card,game,letter,number);
    }else if (card->getAnimal()== 'C'){
        expertCrab(card,game,letter,number);
    }else if (card->getAnimal()== 'W'){
        expertWalrus(card,game,letter,number);
    }else{//Turtle
        expertTurtle(card,game,letter,number);
    }
}

void Rules::expertOctopus(Card* card,const Game &game,Letter letter, Number number){
    cout<<"Octopus"<<endl;
    // When an octopus card is turned over, the
    //card is exchanging position with an adjacent card in the same row or the same column (4-neighbourhood)
    //The adjacent card may be face up or down and will remain unchanged.
}

void Rules::expertPenguin(Card* card,const Game &game,Letter letter, Number number){
    cout<<"Penguin"<<endl;
    //If a player turns over a penguin,
    //then this player is allowed to turn a face-up card face-down. If the penguin is the first card turned up, no
    //special action will take place.

}

void Rules::expertWalrus(Card* card,const Game &game,Letter letter, Number number){
    cout<<"Walrus"<<endl;
//The walrus enables a player to block a face down card for the next player
//and hence the next player must choose another location.
}

void Rules::expertCrab(Card* card,const Game &game,Letter letter, Number number){
    cout<<"Crab"<<endl;
//The player who turns over a crab card must
//immediately turn over another card. If that card does not fit, the player loses the current round.
}

void Rules::expertTurtle(Card* card,const Game &game,Letter letter, Number number){
    cout<<"Turtle"<<endl;
//. Finally,
//with the turtle the next player in the current round is skipped, i.e., the next player will not turn over a card
//and will not lose in the next step.
}