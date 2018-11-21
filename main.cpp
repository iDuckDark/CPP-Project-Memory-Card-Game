#include <iostream>
#include <vector>
#include <queue>
#include <exception>
#include <stdexcept>

#include "game.h"
#include "rules.h"

using namespace std;

void runGame() {
    cout << endl << "Welcome to Nevin's and Peter's Memory Card Game Fall 2018" << endl;
    int mode = 0, nPlayers = 0;
    Game game(mode, nPlayers);
    Rules rules(nPlayers);
    if (mode == 1) {
        while (!rules.gameOver(game)) {
            int sideCounter = 0;
            while (!rules.roundOver(game)) {
                Player &currentPlayer = game.getPlayer(sides[sideCounter++]);
                if (sideCounter >= nPlayers) { sideCounter = 0; }
                cout << "Round: " << game.getRound() << " , Turn: " << currentPlayer.getName() << endl;
                if (currentPlayer.isActive()) { game.setCurrentCard(game.getCard(Z, Zero)); }
                if (!rules.isValid(game)) {
                    currentPlayer.setActive(false);
                    game.setCurrentCard(nullptr);
                }
                cout << game << endl;
            }
            game.nextRound();
        }
        cout << game << endl;
    } else if (mode == 2) {
        //map<string, Card *> cardMap;
        while (!rules.gameOver(game)) {
            //cardMap.clear();
            int sideCounter = 0;
            auto *skipTurn = new bool(false);
            string walrusBlockValue = "Z0";
            while (!rules.roundOver(game)) {
                if (*skipTurn) sideCounter++;
                if (sideCounter >= nPlayers) { sideCounter = 0; }
                const Side &side = sides[sideCounter++];
                *skipTurn = false;
                Player &currentPlayer = game.getPlayer(side);
                if (sideCounter >= nPlayers) { sideCounter = 0; }
                cout << "Round: " << game.getRound() << " , Turn: " << currentPlayer.getName() << endl;
                if (currentPlayer.isActive()) {
                    Letter letter = Z;
                    Number number = Zero;
                    game.getValidInputExpert(&letter, &number);
                    while (game.convertToString(letter, number) == walrusBlockValue) {
                        cout << "Selected Card blocked by walrus" << endl;
                        game.getValidInputExpert(&letter, &number);
                    }
                    Card *selectedCard = game.getCard(letter, number);
                    game.setCard(letter, number, selectedCard); //cardMap[convertToString(letter, number)] = selCard;
                    map<string, Card *> cardMap = game.getCardMap();
                    rules.expertRules(selectedCard, game, letter, number, side, &cardMap, skipTurn,
                                      &walrusBlockValue);
                    cout << game << endl;
                    game.setCurrentCard(selectedCard);
                }
                if (!rules.isValid(game)) {
                    currentPlayer.setActive(false);
                    game.setCurrentCard(nullptr);
                }
            }
            game.nextRound();
            delete skipTurn;
        }
        cout << game << endl;
    }
}


int main() {
    runGame();
//    cout << (0 % 3) << endl;
//    cout << (1 % 3) << endl;
//    cout << (2 % 3) << endl;
//    cout << (3 % 3) << endl;
//    cout << (4 % 3) << endl;
//    cout << (5 % 3) << endl;
//    cout << (6 % 3) << endl;
//    cout << (7 % 3) << endl;
//    int players = 2;
//    int mode = 1;
//    Game game;
//    Player peter("Peter");
//    peter.setSide(Top);
//    Player nevin("Nevin");
//    nevin.setSide(Bottom);
//    game.addPlayer(peter);
//    game.addPlayer(nevin);
//    cout << game.getPlayer(Top) << endl;
//    game.setCurrentCard(game.getCard(A, One));
//    game.setCurrentCard(game.getCard(A, Two));
//    Rules rules;
//    if (!rules.isValid(game)) {
//        peter.setActive(false);
//        game.setCurrentCard(nullptr);
//        cout << "rules valid 1?" << endl;
//    }
//    if (!rules.isValid(game)) {
//        peter.setActive(false);
//        game.setCurrentCard(nullptr);
//        cout << "rules valid 2?" << endl;
//    }
//    cout << "rules valid 3?" << endl;
    return 0;
}

