//
// Created by iDarkDuck on 2018-10-19.
//

#include "rules.h"

#define  TEST_RULES

Rules::Rules(const int &nPlayers) : nPlayers(nPlayers), currentSide(0) {}

bool Rules::isValid(const Game &game) {
    if (twoCardsSelected(game)) return (*game.getPreviousCard() == *game.getCurrentCard());
    return true;
}

bool Rules::gameOver(const Game &game) { return game.getRound() >= 7; }

bool Rules::roundOver(const Game &game) {
    int nActivePlayers = 0;
    for (int i = 0; i < nPlayers; i++) {
        auto player = getNextPlayer(game);
        if (player.isActive()) { nActivePlayers++; }
    }
    return nActivePlayers == 1;
}

const Player &Rules::getNextPlayer(const Game &game) {
    const Game *gamePtr = &game;
    const Player &player = const_cast<Game *>(gamePtr)->getPlayer(sides[currentSide++]);
    if (currentSide >= nPlayers) currentSide = 0;
    return player;
}

bool Rules::twoCardsSelected(const Game &game) const {
    try { return (game.getPreviousCard() != nullptr && game.getCurrentCard() != nullptr); }
    catch (...) { return false; }
}

#ifdef TEST_RULES
#if 0

int main() {
    cout << "TEST_RULES" << endl;
    int sideCounter, nPlayers;
    Game game(sideCounter, nPlayers);
    assert(sideCounter == nPlayers - 1);
    assert(nPlayers >= 2 && nPlayers <= 4);
    Player *currentPlayer = &game.getPlayer(sides[(sideCounter = (sideCounter + 1) % nPlayers)]);
    assert(currentPlayer != nullptr);
    assert(game.getRound() == 1);
    Card *cardPtr = game.getCard(Z, Zero);
    assert(cardPtr != nullptr);
    game.setCurrentCard(cardPtr);
    Card *cardPtr2 = game.getCard(Z, Zero);
    assert(cardPtr2 != nullptr);
    game.setCurrentCard(cardPtr2);
    assert(game.getPreviousCard() != nullptr);
    assert(game.getCurrentCard() != nullptr);
    game.nextRound();
    assert(game.getRound() == 2);
    cout << game << endl;
    //Rules
    Rules rules(nPlayers);
    //Rules Methods
    cout << "Testing for two selected cards" << endl;
    bool isValid = ((*game.getPreviousCard() == *game.getCurrentCard()));
    assert(rules.isValid(game) == isValid);
    assert(rules.gameOver(game) == false);
    assert(rules.roundOver(game) == false);
    const Player *currentPlayerFromRules = &rules.getNextPlayer(game);
    assert(*currentPlayerFromRules == *currentPlayer);
    game.nextRound();
    game.nextRound();
    game.nextRound();
    game.nextRound();
    game.nextRound();
    assert(rules.gameOver(game) == true);
    cout << "Testing Completed" << endl;
}

#endif
#endif