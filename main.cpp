#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <unordered_map>
#include <map> //not used
#include <set> //not used

#include "game.h"
#include "player.h"
#include "card.h"
#include "board.h"
#include "rules.h"

using namespace std;

void pause() {
    cin.clear();
    cout << endl << "Press enter to continue...";
    cin.ignore();
}

void temporaryRevealThreeCards(Game &game) {
    cout << "Three random cards are revealed temporary in front of the players" << endl;
    Board board = game.getBoard();
    for (int i = 0; i < game.getNPlayers(); i++) {
        Player player = game.getPlayer();
        string side = player.getSideOfTheBoard();
        if (side == "top") {
            board.turnFaceUp(A, Two);
            board.turnFaceUp(A, Three);
            board.turnFaceUp(A, Four);
        } else if (side == "bottom") {
            board.turnFaceUp(E, Two);
            board.turnFaceUp(E, Three);
            board.turnFaceUp(E, Four);
        } else if (side == "right") {
            board.turnFaceUp(B, One);
            board.turnFaceUp(C, One);
            board.turnFaceUp(D, One);
        } else {
            board.turnFaceUp(B, Five);
            board.turnFaceUp(C, Five);
            board.turnFaceUp(D, Five);
        }
    }
    cout << game << endl;
    pause();
    cout << "Cards are hidden now" << endl;
    for (int i = 0; i < game.getNPlayers(); i++) {
        Player player = game.getPlayer();
        string side = player.getSideOfTheBoard();

        if (side == "top") {
            board.turnFaceDown(A, Two);
            board.turnFaceDown(A, Three);
            board.turnFaceDown(A, Four);
        } else if (side == "bottom") {
            board.turnFaceDown(E, Two);
            board.turnFaceDown(E, Three);
            board.turnFaceDown(E, Four);
        } else if (side == "right") {
            board.turnFaceDown(B, One);
            board.turnFaceDown(C, One);
            board.turnFaceDown(D, One);
        } else {
            board.turnFaceDown(B, Five);
            board.turnFaceDown(C, Five);
            board.turnFaceDown(D, Five);
        }
    }
    cout << game << endl;
}

void turnFaceUp(Board &board, char letter, int number) {
    unordered_map<char, Letter> letterMap;
    letterMap['A'] = A;
    letterMap['B'] = B;
    letterMap['C'] = C;
    letterMap['D'] = D;
    letterMap['E'] = E;

    unordered_map<int, Number> numberMap;
    numberMap[1] = One;
    numberMap[2] = Two;
    numberMap[3] = Three;
    numberMap[4] = Four;
    numberMap[5] = Five;

    board.turnFaceUp(letterMap[letter], numberMap[number]);
}

void awardActivePlayers(Game &game) {
    for (int i = 0; i < game.getNPlayers(); i++) {
        Player player = game.getPlayer();
        if (player.isActive()) {
            srand(time(NULL));
            int randomRubies = (rand() % 4);
            Reward reward(randomRubies);
            player.addReward(reward);
        }
    }
}

void printLeastToMostRubiesAndWinner(Game &game) {
    set<pair<int, Player> > playersSet;
    for (int i = 0; i < game.getNPlayers(); i++) {
        Player &player = game.getPlayer();
        player.setDisplayMode(true);
        playersSet.insert({player.getNRubies(), player});
    }
    int winCounter = 0;
    for (set<pair<int, Player>>::iterator i = playersSet.begin(); i != playersSet.end(); i++) {
        pair<int, Player> element = *i;
        if (winCounter == game.getNPlayers() - 1) {
            cout << "Winner : ";
        }
        cout << element.second << endl;
        winCounter++;
    }
}

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
        cout << "Invalid input, please try again: " << endl;
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
    Board *board = &game.getBoard();
    cout << game << endl;
    int round = 1;
    while (!rule.gameOver(game)) {
        board->reset();
        game.setAllPlayersActive();
        temporaryRevealThreeCards(game);
        while (!rule.roundOver(game)) {
            for (int i = 0; i < nPlayers; i++) {
                Player &currentPlayer = game.getPlayer();
                cout << "Round: " << round << " , Turn: " << currentPlayer.getName() << endl;
                if (currentPlayer.isActive()) {
                    cout << "Pick a letter from A-E : ";
                    char letter = 'z';
                    while (letter != 'A' && letter != 'B' && letter != 'C' && letter != 'D' && letter != 'E') {
                        cin >> letter;
                        cout << "check 1" << endl;
                    }
                    cout << "Pick a number from 1-5 : ";
                    int number = 0;
                    while (((number != One && number != Two && number != Three && number != Four && number != Five) &&
                            letter == 'C') ||
                           (number != One && number != Two && number != Four && number != Five)) {
                        cout << "check 2" << endl;
                        cin >> number;
                    }
                    cout << "check 3" << endl;
                    //TODO a player can't pick the same card which is already facing up
                    turnFaceUp(*board, static_cast<Letter>(letter), static_cast<Number>(number));
                    Card *selectedCard = board->getCard(static_cast<Letter>(letter), static_cast<Number>(number));
                    game.setCurrentCard(selectedCard);
                    cout << *board << endl;
                }
                cout << "check 4" << endl;
                if (!rule.isValid(game)) {
                    currentPlayer.setActive(false);
                }
                cout << "check 5" << endl;
                cout << game << endl;
            }
        }
        awardActivePlayers(game);
        game.setRound(++round);
    }
    printLeastToMostRubiesAndWinner(game);
}

int main() {
    runGame();
//    Game game;
//    Board *board = &game.getBoard();
//    cout << *board << endl;
//    board->turnFaceUp(B, One);
//    board->turnFaceUp(B, Two);
//    cout << *board << endl;
//    cout << "No Errors" << endl;
    return 0;
}


//board->turnFaceUp(A, One);
//board->turnFaceUp(A, Two);
//board->turnFaceUp(A, Three);
//board->turnFaceUp(A, Four);
//board->turnFaceUp(A, Five);
//
//
//board->turnFaceUp(B, One);
//board->turnFaceUp(B, Two);
//board->turnFaceUp(B, Three);
//board->turnFaceUp(B, Four);
//board->turnFaceUp(B, Five);
//
//board->turnFaceUp(C, One);
//board->turnFaceUp(C, Two);
//board->turnFaceUp(C, Four);
//board->turnFaceUp(C, Five);
//
//
//board->turnFaceUp(D, One);
//board->turnFaceUp(D, Two);
//board->turnFaceUp(D, Three);
//board->turnFaceUp(D, Four);
//board->turnFaceUp(D, Five);
//
//board->turnFaceUp(E, One);
//board->turnFaceUp(E, Two);
//board->turnFaceUp(E, Three);
//board->turnFaceUp(E, Four);
//board->turnFaceUp(E, Five);


//    Player peter{"Peter", "top", 1};
//    Player nevin{"Nevin", "left", 2};
//    Player div{"Divyang", "top", 3};
//    game.addPlayer(peter);
//    game.addPlayer(nevin);
//    game.addPlayer(div);
//
//    cout << game.getPlayer() <<endl;
//    cout << game.getPlayer() <<endl;
//    cout << game.getPlayer() <<endl;
//
//    temporaryRevealThreeCards(*board, peter);