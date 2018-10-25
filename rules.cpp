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
    return game.getRound() >= 7;
}

bool Rules::roundOver(const Game &game) {
    return game.getNActivePlayers() == 1;
}