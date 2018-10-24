//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_GAME_H
#define CPP_PROJECT_MEMORY_GAME_GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include "player.h"
#include "card.h"
#include "board.h"

class Game {

private:
    int nRound;
    int nPlayers;
    queue<Player> playersQueue;
    vector<const Card *> cards;
    Board board;

public:

    Game() = default;

    int getRound() const;

    int getNPlayers() const;

    int getNActivePlayers() const;

    Board &getBoard(); //TODO not sure if this is bad

    void setRound(int nRound);

    void addPlayer(const Player &);

    Player &getPlayer();

    void setAllPlayersActive() const; //Added own function

    const Card *getPreviousCard() const;

    const Card *getCurrentCard() const;

    void setCurrentCard(const Card *);

    friend ostream &operator<<(ostream &os, const Game &game);

};


#endif //CPP_PROJECT_MEMORY_GAME_GAME_H
