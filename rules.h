//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_RULES_H
#define CPP_PROJECT_MEMORY_GAME_RULES_H

#include <stdexcept>
#include "game.h"

class Rules {

public:

    explicit Rules(const int &nPlayers = 0);

    bool isValid(const Game &game);

    bool gameOver(const Game &game);

    bool roundOver(const Game &game);

    const Player &getNextPlayer(const Game &);

private:

    int nPlayers;
    int currentSide;

    bool twoCardsSelected(const Game &) const;
};

#endif //CPP_PROJECT_MEMORY_GAME_RULES_H
