//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_RULES_H
#define CPP_PROJECT_MEMORY_GAME_RULES_H

#include <iostream>
#include <string>
#include "game.h"

class Rules {
    bool isValid(const Game &);

    bool gameOver(const Game &);

    bool roundOver(const Game &);
};


#endif //CPP_PROJECT_MEMORY_GAME_RULES_H
