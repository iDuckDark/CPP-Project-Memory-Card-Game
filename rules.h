//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_RULES_H
#define CPP_PROJECT_MEMORY_GAME_RULES_H

#include <iostream>
#include <string>
#include "game.h"

class Rules {

private:
    int nPlayers;
    int currentSide;
    string walrusBlockValue = "Z0";

    bool twoCardsSelected(const Game &) const;

    char LetterToChar(const Letter &letter); //Expert

    string convertToString(const Letter &letter, const Number &number); //Expert

public:

    explicit Rules(int nPlayers = 0);

    bool isValid(const Game &game);

    bool gameOver(const Game &game);

    bool roundOver(const Game &game);

    const Player &getNextPlayer(Game &);

    void handleExpertRules(Game &game, const Side &side, bool &skipTurn);

    void expertRules(Card *, Game &, Letter &, Number &, const Side &, map<string, Card *> *, bool &, string *);

    void expertOctopus(Card *, Game &, Letter &, Number &, const Side &, map<string, Card *> *);

    void expertPenguin(Card *, Game &, Letter &, Number &, const Side &, map<string, Card *> *);

    void expertWalrus(Card *, Game &, Letter &, Number &, const Side &, string *);

    void expertCrab(Card *, Game &, Letter &, Number &, const Side &);

    void expertTurtle(Card *, Game &, Letter &, Number &, const Side &, bool &);
};


#endif //CPP_PROJECT_MEMORY_GAME_RULES_H
