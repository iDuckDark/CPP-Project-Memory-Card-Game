//
// Created by iDarkDuck on 2018-10-19.
//

#include "rules.h"

bool Rules::isValid(const Game &game) {
    cout << endl << "TEST RULES IS VALID? " << endl;
    if (game.twoCardsSelected()) {
        cout << "Previous & Next card Equal? " << (*game.getPreviousCard() == *game.getCurrentCard()) << endl
             << *game.getPreviousCard() << endl << *game.getCurrentCard() << endl;
        return (*game.getPreviousCard() == *game.getCurrentCard());
    }
    cout << "NO TWO CARDS SELECTED" << endl << endl;
    return false;
}

bool Rules::gameOver(const Game &game) {
    return game.getRound() >= 7;
}

bool Rules::roundOver(const Game &game) {
    return game.getNActivePlayers() == 1;
}


void Rules::expertRules(Card *card, Game &game, Letter letter, Number number) {
    if (card->getAnimal() == 'O') {
        expertOctopus(card, game, letter, number);
    } else if (card->getAnimal() == 'P') {
        expertPenguin(card, game, letter, number);
    } else if (card->getAnimal() == 'C') {
        expertCrab(card, game, letter, number);
    } else if (card->getAnimal() == 'W') {
        expertWalrus(card, game, letter, number);
    } else {//Turtle
        expertTurtle(card, game, letter, number);
    }
}

void Rules::expertOctopus(Card *card, Game &game, Letter letter, Number number) {
    cout << "You have picked an Octopus!" << endl;
    cout << "Pick position with an adjacent card in the same row or the same column " << endl;

    //TODO Get input and implement logic

    // When an octopus card is turned over, the
    //card is exchanging position with an adjacent card in the same row or the same column (4-neighbourhood)
    //The adjacent card may be face up or down and will remain unchanged.
}

void Rules::expertPenguin(Card *card, Game &game, Letter letter, Number number) {
    cout << "You have picked a Penguin!" << endl;
    cout << "Pick a card to change face up or face down " << endl;
    //TODO Get input and implement logic
    //If the penguin is the first card turned up, no
    //special action will take place.

}

void Rules::expertWalrus(Card *card, Game &game, Letter letter, Number number) {
    cout << "You have picked a Walrus!" << endl;
    cout << "Pick a card to block from being chosen in the next round" << endl;
    //TODO Get input and implement logic
}

void Rules::expertCrab(Card *card, Game &game, Letter letter, Number number) {
    cout << "You have picked a Crab!" << endl;
    cout << "Pick another card. If it doesn't match, you lose the round" << endl;
    //TODO Get input and implement logic

    //The player who turns over a crab card must
    //immediately turn over another card. If that card does not fit, the player loses the current round.
}

void Rules::expertTurtle(Card *card, Game &game, Letter letter, Number number) {
    cout << "You have picked a Turtle!" << endl;
    cout << "Skipping next player's turn." << endl;
    //TODO Get input and implement logic
    //. Finally,
    //with the turtle the next player in the current round is skipped, i.e., the next player will not turn over a card
    //and will not lose in the next step.
}