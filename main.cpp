#include "rules.h"

void runGame() {
    int mode = 0, nPlayers = 0;
    Game game(mode, nPlayers);
    Rules rules(nPlayers);
    while (!rules.gameOver(game)) {
        int sideCounter = nPlayers - 1;
        while (!rules.roundOver(game)) {
            Player &currentPlayer = game.getPlayer(sides[(sideCounter = (sideCounter + 1) % nPlayers)]);
            cout << "Round: " << game.getRound() << " , Turn: " << currentPlayer.getName() << endl;
            if (currentPlayer.isActive()) {
                if (mode == 1) game.setCurrentCard(game.getCard(Z, Zero));
                else rules.expertRules(game, sideCounter);
            }
            if (!rules.isValid(game)) currentPlayer.setActive(false);
            game.setCurrentCard(nullptr);
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


