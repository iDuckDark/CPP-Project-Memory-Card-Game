//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_GAME_H
#define CPP_PROJECT_MEMORY_GAME_GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <cassert>

#include "player.h"
#include "card.h"
#include "board.h"

class Game {

private:
    int nRound;

    Board board;

public:
    queue<vector<const Card *>> cardQueue;

    queue<Player> playersQueue;

    Game() = default;

    int getRound() const;

    int getNPlayers() const;

    int getNActivePlayers() const;

    bool twoCardsSelected() const;

    Board &getBoard(); //TODO not sure if this is bad

    void setRound(int nRound);

    void addPlayer(const Player &);

    void setPlayersActive(bool active);

    Player &getPlayer();

    void setAllPlayersActive(); //Added own function

    const Card *getPreviousCard() const;

    const Card *getCurrentCard() const;

    void setCurrentCard(const Card *);

    void clearSelectedCards();

    friend ostream &operator<<(ostream &os, const Game &game);
};


#endif //CPP_PROJECT_MEMORY_GAME_GAME_H
