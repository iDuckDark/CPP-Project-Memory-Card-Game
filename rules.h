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
    Rules() = default;

    bool isValid(const Game &game);

    bool gameOver(const Game &game);

    bool roundOver(const Game &game);

    void expertRules(Card *, Game &, Letter &, Number &, const Side &, std::map<std::string, Card *> *, bool*);

    void expertOctopus(Card *, Game &, Letter &, Number &, const Side &);

    void expertPenguin(Card *, Game &, Letter &, Number &, const Side &, std::map<std::string, Card *> *);

    void expertWalrus(Card *, Game &, Letter &, Number &, const Side &);

    void expertCrab(Card *, Game &, Letter &, Number &, const Side &);

    void expertTurtle(Card *, Game &, Letter &, Number &, const Side &, bool*);
};


#endif //CPP_PROJECT_MEMORY_GAME_RULES_H
