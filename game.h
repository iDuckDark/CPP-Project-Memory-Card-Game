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

class Rules;

const vector<Side> sides = {Top, Bottom, Left, Right};

class Game {

private:

    int mode{0};
    int nRound{0};
    Side currentSide;
    vector<Player> players;
    Board board;
    RewardDeck rewardDeck;
    vector<vector<const Card *>> cards;

    void setSide(Side);

    void setMode(int &);

    void createPlayers(int &);

    void makeCardDeck();

    void setAllPlayersActive();

    void temporaryRevealThreeCards(const int &mode);

    void getValidInput(Letter *letter, Number *number);

    void awardActivePlayers();

    void printLeastToMostRubiesAndWinner() const;

public:

    Game(int &, int &);

    void setRound(int &);

    int getRound() const;

    void addPlayer(const Player &);

    Player &getPlayer(Side);

    const Card *getPreviousCard() const;

    const Card *getCurrentCard() const;

    void setCurrentCard(const Card *);

    Card *getCard(const Letter &, const Number &);

    void setCard(const Letter &, const Number &, Card *);

    friend ostream &operator<<(ostream &os, const Game &game);

    //TODO minimize own public functions
    void reset(const int &);

    int getNActivePlayers() const;

    void getValidInputExpert(Letter *letter, Number *number);

    bool twoCardsSelected() const;

    void clearSelectedCards();

    bool isValidCard(const Letter &letter, const Number &number) const;

    bool isBlocked(const Letter &, const Number &) const; //Expert Walrus

    void setBlocked(const Letter &, const Number &); //Expert Walrus
};


#endif //CPP_PROJECT_MEMORY_GAME_GAME_H
