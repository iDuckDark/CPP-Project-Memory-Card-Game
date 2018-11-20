#include <iostream>
#include <vector>
#include <queue>
#include <exception>
#include <stdexcept>

#include "game.h"
#include "rules.h"

using namespace std;

void expertModePrint(std::map<std::string, Card *> cardMap) {
    for (int i = 0; i < 3; i++) {
        for (auto const&[key, val] : cardMap) { cout << (*val)(i) << " "; }
        cout << endl;
    }
    for (auto const &card : cardMap) { cout << card.first << "  "; }
    cout << endl;
}

string convertToString(Letter letter, Number number){
    char cara = 'Z';
    if (letter == A) { cara = 'A'; }
    else if (letter == B) { cara = 'B'; }
    else if (letter == C) { cara = 'C'; }
    else if (letter == D) { cara = 'D'; }
    else if (letter == E) { cara = 'E'; }
    return(cara+to_string(number));
}

void runGame() {
    cout << endl;
    cout << "Welcome to Nevin's and Peter's Memory Card Game Fall 2018" << endl;
    int mode = 0, nPlayers;
    Game game(mode, nPlayers);
    Rules rules(nPlayers);
    if (mode == 1) {
        int round = 1;
        while (!rules.gameOver(game)) {
            game.reset();
            int sideCounter = 0;
            while (!rules.roundOver(game)) {
                Player &currentPlayer = game.getPlayer(sides[sideCounter++]);
                if (sideCounter >= nPlayers) { sideCounter = 0; }
                cout << "Round: " << round << " , Turn: " << currentPlayer.getName() << endl;
                if (currentPlayer.isActive()) { game.setCurrentCard(game.getCard(Z, Zero)); }
                if (!rules.isValid(game)) { if (game.twoCardsSelected()) currentPlayer.setActive(false); }
                if (game.twoCardsSelected()) { game.clearSelectedCards(); }
                cout << game << endl;
            }
            game.setRound(++round);
        }
        cout << game << endl;
    } else if (mode == 2) {
        std::map<std::string, Card *> cardMap;
        int round = 1;
        while (!rules.gameOver(game)) {
            game.reset();
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
                cout << "Round: " << round << " , Turn: " << currentPlayer.getName() << endl;
                if (currentPlayer.isActive()) {
                    Letter letter = Z;
                    Number number = Zero;
                    game.getValidInputExpert(&letter, &number);
                    while(convertToString(letter,number)==walrusBlockValue){
                        cout<<"Selected Card blocked by walrus"<<endl;
                        game.getValidInputExpert(&letter, &number);
                    }
                    cout << letter << number << " FIXED???" << endl;
                    Card *selectedCard = game.getCard(letter, number);
                    cardMap[convertToString(letter,number)] = selectedCard;
                    rules.expertRules(selectedCard, game, letter, number, side, &cardMap, skipTurn, &walrusBlockValue);
                    //TODO fix letter and number input?
                    expertModePrint(cardMap);
                    game.setCurrentCard(selectedCard);
                }
                if (!rules.isValid(game)) { if (game.twoCardsSelected()) { currentPlayer.setActive(false); }}
                if (game.twoCardsSelected()) { game.clearSelectedCards(); }
            }
            game.setRound(++round);
            delete skipTurn;
        }

        cout << game << endl;
    }
}


int main() {
    runGame();
//    Game game;
//    Player peter("Peter");
//    peter.setSide(Top);
//    Player nevin("Nevin");
//    nevin.setSide(Bottom);
//    game.addPlayer(peter);
//    game.addPlayer(nevin);
//    Player div{"Divyang"};
//    div.setSide(Left);
//    game.addPlayer(div);
//
//    game.setCard(A, Two, nullptr);
//    cout << game << endl;
    return 0;
}

