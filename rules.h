//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_RULES_H
#define CPP_PROJECT_MEMORY_GAME_RULES_H

#include "game.h"

class Rules {

private:
    int nPlayers;
    int currentSide;
    string walrusBlockValue;

    bool twoCardsSelected(const Game &) const;

    char LetterToChar(const Letter &); //Expert

    string convertToString(const Letter &, const Number &); //Expert

public:

    explicit Rules(int nPlayers = 0);

    bool isValid(const Game &game);

    bool gameOver(const Game &game);

    bool roundOver(const Game &game);

    const Player &getNextPlayer(const Game &);

    void handleExpertRules(Game &game, int &sideCounter);

    void expertRules(Card *, Game &, Letter &, Number &, int &);

    void expertOctopus(Card *, Game &, Letter &, Number &);

    void expertPenguin(Game &, int &);

    void expertWalrus(Game &);

    void expertCrab(Card *, Game &, Letter &, Number &, int &);

    void expertTurtle(int &sideCounter);
};


#endif //CPP_PROJECT_MEMORY_GAME_RULES_H
