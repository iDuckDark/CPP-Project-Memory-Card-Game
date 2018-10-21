//
// Created by iDarkDuck on 2018-10-19.
//

#include "rules.h"


bool Rules::isValid(const Game &game) {
    return game.getPreviousCard() == game.getCurrentCard();
}

bool Rules::gameOver(const Game &game) {
    return game.getRound() == 7;
}

bool Rules::roundOver(const Game &game) {
    return game.getPlayers().size() == 1;
}