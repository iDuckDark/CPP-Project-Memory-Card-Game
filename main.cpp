#include <iostream>
#include <string>
#include <vector>

#include "game.h"
#include "player.h"
#include "card.h"
#include "board.h"
#include "rules.h"

using namespace std;

void runGame() {
    cout << endl;
    cout << "Welcome to Nevin's and Peter's Memory Card Game Fall 2018" << endl;

    cout << "Please choose your game version:" << endl;
    cout << "Enter 1 for Base Mode and 2 for Expect Mode: ";
    int mode = 0;
    cin >> mode;
    while (mode != 1 && mode != 2) {
        cout << "Invalid input, please try again: " << endl;
        cin >> mode;
    }
    cout << "Number of Players " << "(Minimum 2 - Maximum 4) : ";
    int nPlayers = 0;
    cin >> nPlayers;
    while ((nPlayers < 2 || nPlayers > 4)) {
        cout << "Invalid input, please try again" << endl;
        cin >> nPlayers;
    }

    string names[nPlayers];
    for (int i = 0; i < nPlayers; i++) {
        cout << "Enter name for Player number " << (i + 1) << ": ";
        cin >> names[i];
    }
    Game game;
    string sides[4] = {"top", "bottom", "left", "right"};
    for (int i = 0; i < nPlayers; i++) {
        Player player(names[i], sides[i], 0);
        game.addPlayer(player);
    }
    Rules rule;
    Board board;
    while (!rule.gameOver(game)) {
        board.reset();
        vector<Player> players = game.getPlayers();
        game.setAllPlayersActive();
        //TODO Temporarily reveal 3 cards directly in front of the player
        while (!rule.roundOver(game)) {
            for (int i = 0; i < nPlayers; i++) {
                if (players[i].isActive()) {
                    //TODO # next active player takes a turn
                    //TODO get selection of card to turn face up from active player
                    //TODO update board in game
                }
                if (!rule.isValid(game) {
                    players[i].setActive(false);
                }
                cout << board;
            }
        }
        //TODO Remaining active player receives reward (rubies)
    }
    //TODO print players with their number of rubies sorted from least to most
    //TODO rubies
    //TODO print overall winner
}

int main() {
    //Runs the game
    //runGame();
    cout << "No Errors" << endl;
    return 0;
}

//    static CardDeck* cardDeck = &CardDeck::make_CardDeck();