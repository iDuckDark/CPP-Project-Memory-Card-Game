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

#include "player.h"
#include "card.h"
#include "board.h"
#include "rewarddeck.h"

class Game {

private:
    int nRound{0};

    Side currentSide;

    Board board;

    RewardDeck rewardDeck;

    vector<vector<const Card *>> cards;

    vector<Player> players;

    void setSide(Side);

    void temporaryRevealThreeCards(const int &mode);

public:

    Game() = default;

    void setRound(int &);

    int getRound() const;

    void addPlayer(const Player &);

    Player &getPlayer(Side);

    const Card *getPreviousCard() const;

    const Card *getCurrentCard() const;

    void setCurrentCard(const Card *);

    Card *getCard(const Letter &, const Number &);

    void setCard(const Letter &, const Number &, Card *);

    //TODO minimize own public methods

    int getNPlayers() const;

    int getNActivePlayers() const;

    bool twoCardsSelected() const;

    void reset(const int &);

    void setAllPlayersActive();

    void clearSelectedCards();

    void awardActivePlayers();

    void getValidInput(Letter *letter, Number *number);

    friend ostream &operator<<(ostream &os, const Game &game);
};


#endif //CPP_PROJECT_MEMORY_GAME_GAME_H
