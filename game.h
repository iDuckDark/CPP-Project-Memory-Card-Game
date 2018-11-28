//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_GAME_H
#define CPP_PROJECT_MEMORY_GAME_GAME_H

#include <map>
#include <stdexcept>
#include "board.h"
#include "player.h"
#include "card.h"
#include "rewarddeck.h"

inline const extern vector<Side> sides = {Side::Top, Side::Bottom, Side::Left, Side::Right};

class Game {

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

    friend ostream &operator<<(ostream &, const Game &);

    void nextRound();

private:

    int mode{0};
    int nRound{0};
    Side currentSide;
    vector<Player> players;
    Board board;
    vector<vector<const Card *>> cards;
    vector<const Reward *> rewardDeck;
    map<string, Card *> cardMap;
    bool ready = false;
    string walrusBlockValue;
    int &sideCounter;

    void setSide(Side);

    void setMode();

    void createPlayers(int &);

    bool containsPlayer(const Player &);

    void makeCardDeck();

    void makeRewardDeck();

    void setAllPlayersActive();

    void temporaryRevealThreeCards();

    void getValidInput(Letter *letter, Number *number, const FaceAnimal &);

    int toEnum(const char &);

    void awardActivePlayers();

    void printLeastToMostRubiesAndWinner() const;

    void expertModePrint() const;

    bool twoCardsSelected() const;

    void clearSelectedCards();

    void reset();

    char LetterToChar(const Letter &);

    string convertToString(const Letter &, const Number &);

    bool isValidCard(const Letter &letter, const Number &number);

    Card *getExpertCard(Letter &, Number &, const FaceAnimal &);

    Card *getExpertCard(const Letter &, const Number &);

    void setExpertCurrentCard(const Card *);

    void getExpertRulesInput();

    void expertRules(Card *, Letter &, Number &, int &);

    void expertOctopus(Card *, Letter &, Number &);

    void expertPenguin(int &);

    void expertWalrus();

    void expertCrab(Card *, Letter &, Number &, int &);

    void expertTurtle();

    void swapCards(const Letter &, const Number &, const Letter &, const Number &);

    map<string, Card *> &getCardMap();
};

#endif //CPP_PROJECT_MEMORY_GAME_GAME_H
