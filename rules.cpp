//
// Created by iDarkDuck on 2018-10-19.
//

#include "rules.h"
#define  TEST_RULES
Rules::Rules(const int &nPlayers) : nPlayers(nPlayers), currentSide(0){}

bool Rules::isValid(const Game &game) {
    if (twoCardsSelected(game)) return (*game.getPreviousCard() == *game.getCurrentCard());
    return true;
}

bool Rules::twoCardsSelected(const Game &game) const {
    try { return (game.getPreviousCard() != nullptr && game.getCurrentCard() != nullptr); }
    catch (...) { return false; }
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


#ifdef TEST_RULES
#if 0
int main() {
    cout<<"TEST_RULES"<<endl;
}
#endif
#endif