#include <iostream>
#include <vector>
#include <queue>
#include <exception>
#include <stdexcept>

#include "game.h"
#include "rules.h"

using namespace std;

void runGame() {
    int mode = 0, nPlayers = 0;
    Game game(mode, nPlayers);
    Rules rules(nPlayers);
    while (!rules.gameOver(game)) {
        int sideCounter = 0;
        bool skipTurn = false;
        while (!rules.roundOver(game)) {
            if (skipTurn) sideCounter++;
            if (sideCounter >= nPlayers) { sideCounter = 0; }
            const Side &side = sides[sideCounter++];
            Player &currentPlayer = game.getPlayer(side);
            if (sideCounter >= nPlayers) { sideCounter = 0; }
            cout << "Round: " << game.getRound() << " , Turn: " << currentPlayer.getName() << endl;
            if (currentPlayer.isActive()) {
                if (mode == 1) game.setCurrentCard(game.getCard(Z, Zero));
                else rules.handleExpertRules(game, side, skipTurn);
            }
            if (!rules.isValid(game)) {
                currentPlayer.setActive(false);
                game.setCurrentCard(nullptr);
            }
            cout << game << endl;
        }
        game.nextRound();
    }
    cout << game << endl;
}


int main() {
    runGame();
    return 0;
}

