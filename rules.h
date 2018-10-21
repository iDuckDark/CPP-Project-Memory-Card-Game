//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_RULES_H
#define CPP_PROJECT_MEMORY_GAME_RULES_H

#include <iostream>
#include <string>
#include "game.h"

class Rules {

    Rules()= default;

    bool isValid(const Game &game);

    bool gameOver(const Game &game);

    bool roundOver(const Game &game);
};


#endif //CPP_PROJECT_MEMORY_GAME_RULES_H
