//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_GAME_H
#define CPP_PROJECT_MEMORY_GAME_GAME_H

#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "card.h"


class Game {

private:
    int nRound;
    vector<Player> players;
    vector<Card> cards;

public:
    int getRound();

    void addPlayer(const Player &);

    Player &getPlayer();

    const Card *getPreviousCard();

    const Card *getCurrentCard();

    void setCurrentCard(const Card *);

};


#endif //CPP_PROJECT_MEMORY_GAME_GAME_H
