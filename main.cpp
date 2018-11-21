#include <iostream>
#include <vector>
#include <queue>
#include <exception>
#include <stdexcept>

#include "game.h"
#include "rules.h"

using namespace std;

void expertModePrint(map<string, Card *> cardMap) {
    for (int i = 0; i < 3; i++) {
        for (auto const&[key, val] : cardMap) { cout << (*val)(i) << " "; }
        cout << endl;
    }
    for (auto const &card : cardMap) { cout << card.first << "  "; }
    cout << endl;
}

string convertToString(Letter letter, Number number) {
    char cara = 'Z';
    if (letter == A) { cara = 'A'; }
    else if (letter == B) { cara = 'B'; }
    else if (letter == C) { cara = 'C'; }
    else if (letter == D) { cara = 'D'; }
    else if (letter == E) { cara = 'E'; }
    return (cara + to_string(number));
}

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
        map<string, Card *> cardMap;
        while (!rules.gameOver(game)) {
            cardMap.clear();
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
                    while (convertToString(letter, number) == walrusBlockValue) {
                        cout << "Selected Card blocked by walrus" << endl;
                        game.getValidInputExpert(&letter, &number);
                    }
                    Card *selectedCard = game.getCard(letter, number);
                    cardMap[convertToString(letter, number)] = selectedCard;
                    rules.expertRules(selectedCard, game, letter, number, side, &cardMap, skipTurn,
                                      &walrusBlockValue);
                    expertModePrint(cardMap);
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
//    bool *faceDownCards[5];
//    for (auto &faceDownCard : faceDownCards) {
//        faceDownCard = new bool[5];
//        for (int y = 0; y < 5; y++) { faceDownCard[y] = true; }
//    }
//    faceDownCards[0][0] = false;
//
//    bool &first = faceDownCards[0][0];
//    bool &second = faceDownCards[1][1];
//    cout << first << endl;
//    cout << second << endl;
//    bool temp = first;
//    first = second;
//    second = temp;
//
//    cout << first << endl;
//    cout << second << endl;

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
    //cout << (peter == nevin) << endl;
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

