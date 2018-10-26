//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_RULES_H
#define CPP_PROJECT_MEMORY_GAME_RULES_H

#include <iostream>
#include <string>
#include "game.h"

class Rules {

public:
    Rules()= default;

    bool isValid(const Game &game);

    bool gameOver(const Game &game);

    bool roundOver(const Game &game);
    void expertRules(const Card&, const Game&, Letter, Number);
    void expertOctopus(const Card&, const Game&, Letter, Number);
    void expertPenguin(const Card&, const Game&, Letter, Number);
    void expertWalrus(const Card&, const Game&, Letter, Number);
    void expertCrab(const Card&, const Game&, Letter, Number);
    void expertTurtle(const Card&, const Game&, Letter, Number);
};


#endif //CPP_PROJECT_MEMORY_GAME_RULES_H
