#include <iostream>
#include <vector>
#include <queue>
#include <exception>
#include <stdexcept>

#include "game.h"
#include "rules.h"

using namespace std;

void setMode(int &mode) {
    cout << "Please choose your game version:" << endl;
    cout << "Enter 1 for Base Mode and 2 for Expect Mode: ";
    while (true) {
        char input;
        cin >> input;
        mode = ((int) input - 48);
        if (mode == 1 || mode == 2) break;
        else cout << "Invalid input, please try again: ";
    }
}

void createPlayers(Game &game, int &nPlayers, const vector<Side> &sides) {
    cout << "Number of Players " << "(Minimum 2 - Maximum 4) : ";
    cin >> nPlayers;
    while ((nPlayers < 2 || nPlayers > 4)) {
        cout << "Invalid input, please try again: " << endl;
        cin >> nPlayers;
    }
    vector<string> names(static_cast<unsigned long>(nPlayers));
    for (int i = 0; i < nPlayers; i++) {
        cout << "Enter name for Player number " << (i + 1) << ": ";
        cin >> names[i];
    }
    for (int i = 0; i < nPlayers; i++) {
        Player player{names[i]};
        player.setSide(sides[i]);
        game.addPlayer(player);
    }
}

void makeCardDeck(Game &game) {
    CardDeck &deck = CardDeck::make_CardDeck();
    int i = 1, j = 1;
    while (!deck.isEmpty()) {
        game.setCard(static_cast<Letter>(i), static_cast<Number>(j++), deck.getNext());
        if (j == 5) {
            j = 0;
            i++;
        }
    }
}

void expertModePrint(std::map<std::string, Card *> cardMap) {
    for (int i = 0; i < 3; i++) {
        for (auto const&[key, val] : cardMap) { cout << (*val)(i) + " "; }
        cout << endl;
    }
    for (auto const&[key, val] : cardMap) { cout << key + "  "; }
    cout << endl;
}

void runGame() {
    cout << endl;
    cout << "Welcome to Nevin's and Peter's Memory Card Game Fall 2018" << endl;
    int mode = 0, nPlayers;
    setMode(mode);
    Game game;
    Rules rules;
    const vector<Side> sides = {Top, Bottom, Left, Right};
    createPlayers(game, nPlayers, sides);
    makeCardDeck(game);
    if (mode == 1) {
        int round = 1;
        while (!rules.gameOver(game)) {
            game.reset(mode);
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
    }
    else if (mode == 2) {
        std::map<std::string, Card *> cardMap;
        int round = 1;
        while (!rules.gameOver(game)) {
            game.reset(mode);
            int sideCounter = 0;
            bool *skipTurn = new bool(false);
            while (!rules.roundOver(game)) {
                if (*skipTurn) sideCounter++;
                const Side &side = sides[sideCounter++];
                *skipTurn = false;
                Player &currentPlayer = game.getPlayer(side);
                if (sideCounter >= nPlayers) { sideCounter = 0; }
                cout << "Round: " << round << " , Turn: " << currentPlayer.getName() << endl;
                if (currentPlayer.isActive()) {
                    Letter letter = Z;
                    Number number = Zero;
                    Card *selectedCard = game.getCard(Z, Zero);
                    rules.expertRules(selectedCard, game, letter, number, side, &cardMap, skipTurn);
                    //TODO fix letter and number input
                    char cara = 'Z';
                    if (letter == A) { cara = 'A'; }
                    else if (letter == B) { cara = 'B'; }
                    else if (letter == C) { cara = 'C'; }
                    else if (letter == D) { cara = 'D'; }
                    else if (letter == E) { cara = 'E'; }
                    cardMap[cara + to_string(number)] = selectedCard;
                    expertModePrint(cardMap);
                    game.setCurrentCard(selectedCard);
                }
                if (!rules.isValid(game)) { if (game.twoCardsSelected()) { currentPlayer.setActive(false); }}
                if (game.twoCardsSelected()) { game.clearSelectedCards(); }
            }
            game.setRound(++round);
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

