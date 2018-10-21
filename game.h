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
    vector<const Card*> cards;

public:
    int getRound() const;

    void addPlayer(const Player &);

    Player &getPlayer(); //Not used???????

    vector<Player> getPlayers() const; //Added own function

    const Card *getPreviousCard() const;

    const Card *getCurrentCard() const;

    void setCurrentCard(const Card *);

};


#endif //CPP_PROJECT_MEMORY_GAME_GAME_H
