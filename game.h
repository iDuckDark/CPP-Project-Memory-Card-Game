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
#include <stdexcept>

#include "player.h"
#include "card.h"
#include "board.h"
#include "rewarddeck.h"

const vector<Side> sides = {Top, Bottom, Left, Right};

class Game {

private:

    int mode{0};
    int nRound{0};
    Side currentSide;
    vector<Player> players;
    Board board;
    vector<vector<const Card *>> cards;
    vector<const Reward *> rewardDeck;
    //map<string, Card *> cardMap; //Expert Mode
    //bool ready = false;

    void setSide(Side);

    void setMode(int &);

    void createPlayers(int &);

    bool containsPlayer(const Player&);

    void makeCardDeck();

    void makeRewardDeck();

    void setAllPlayersActive();

    void temporaryRevealThreeCards();

    void getValidInput(Letter *letter, Number *number);

    void awardActivePlayers();

    void printLeastToMostRubiesAndWinner() const;

    void expertModePrint() const;

    void clearSelectedCards();

    void reset();

    bool isValidCard(const Letter &letter, const Number &number) const;

    bool isBlocked(const Letter &, const Number &) const; //Expert Walrus

    void setBlocked(const Letter &, const Number &); //Expert Walrus

public:

    Game(int &, int &);

    int getRound() const;

    void addPlayer(const Player &);

    Player &getPlayer(Side);

    const Card *getPreviousCard() const;

    const Card *getCurrentCard() const;

    void setCurrentCard(const Card *);

    Card *getCard(const Letter &, const Number &);

    void setCard(const Letter &, const Number &, Card *);

    friend ostream &operator<<(ostream &os, const Game &game);

    void nextRound();

    //TODO minimize own public functions

    int getNActivePlayers() const;

    //map<string, Card *> &getCardMap();

    void getValidInputExpert(Letter *letter, Number *number);

    void hideCard(const Letter &letter, const Number &number); //Expert penguin

    void getValidInputExpertOct(Letter *letter, Number *number);

    void swapCards(const Letter &, const Number &, const Letter &, const Number &); //Expert Octopus

    //string convertToString(const Letter &letter, const Number &number); //Expert

};


#endif //CPP_PROJECT_MEMORY_GAME_GAME_H
