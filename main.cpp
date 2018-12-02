#define MAIN

#include "rules.h"

void runGame() {
    int sideCounter = 0, nPlayers = 0;
    Game game(sideCounter, nPlayers);
    Rules rules(nPlayers);
    while (!rules.gameOver(game)) {
        sideCounter = nPlayers - 1;
        while (!rules.roundOver(game)) {
            Player &currentPlayer = game.getPlayer(sides[(sideCounter = (sideCounter + 1) % nPlayers)]);
            cout << "Round: " << game.getRound() << " , Turn: " << currentPlayer.getName() << endl;
            if (currentPlayer.isActive()) { game.setCurrentCard(game.getCard(Z, Zero)); }
            if (!rules.isValid(game)) currentPlayer.setActive(false);
            game.setCurrentCard(nullptr);
            cout << game << endl;
        }
        game.nextRound();
    }
    cout << game << endl;
}

#ifdef MAIN
#if 1
int main() {
    runGame();
    return 0;
}
#endif
#endif