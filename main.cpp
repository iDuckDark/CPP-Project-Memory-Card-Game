#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <map> //not used
#include <set> //not used
#include <queue>

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
    Board *board = &game.getBoard();
    for (int i = 0; i < game.getNPlayers(); i++) {
        Player player = game.getPlayer();
        string side = player.getSideOfTheBoard();
        if (side == "top") {
            board->turnFaceUp(A, Two);
            board->turnFaceUp(A, Three);
            board->turnFaceUp(A, Four);
        } else if (side == "bottom") {
            board->turnFaceUp(E, Two);
            board->turnFaceUp(E, Three);
            board->turnFaceUp(E, Four);
        } else if (side == "right") {
            board->turnFaceUp(B, One);
            board->turnFaceUp(C, One);
            board->turnFaceUp(D, One);
        } else {
            board->turnFaceUp(B, Five);
            board->turnFaceUp(C, Five);
            board->turnFaceUp(D, Five);
        }
    }
    cout << game << endl;
    //pause();
    cout << "Cards are hidden now" << endl;
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
            int randomRubies = (rand() % 4) + 1;
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

bool validLetter(char letter) {
    return letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E';
}

bool validNumber(int number, char letter) {
    if (letter == 'C') {
        return number == One || number == Two || number == Four || number == Five;
    } else {
        return number == One || number == Two || number == Three || number == Four || number == Five;
    }
}

int convert2Char(char *letter) {
    int num = -1;
    if (*letter == 'A') {
        num = 0;
    } else if (*letter == 'B') {
        num = 1;
    } else if (*letter == 'C') {
        num = 2;
    } else if (*letter == 'D') {
        num = 3;
    } else if (*letter == 'E') {
        num = 4;
    } else {
        num = -1;
    }
    return num;
}


void getValidInput(char *letter, int *number, Board *board) {
    do {
        *letter = 'z';
        while (!validLetter(*letter)) {
            cout << "Pick a letter from A-E : ";
            cin >> *letter;
        }
        *number = -1;
        while (!validNumber(*number, *letter)) {
            cout << "Pick a number from 1-5 : ";
            cin >> *number;
        }
        if (!(board->isFaceDown(convert2Char(letter), *number - 1))) {
            cout << "Card already up!" << endl;
        }
        cout << "HERE" << endl;
    } while (!(board->isFaceDown(convert2Char(letter), *number - 1)));
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
    Rules rules;
    Board *board = &game.getBoard();

    int round = 1;
    while (!rules.gameOver(game)) {
        board->reset();
        game.setAllPlayersActive();
        temporaryRevealThreeCards(game);
        board->reset();
        while (!rules.roundOver(game)) { //{Peter , Nevin, Divyang }

            Player &currentPlayer = game.getPlayer(); // , Nevin, Divyang, Peter  but now is Peter
            cout << "Round: " << round << " , Turn: " << currentPlayer.getName() << endl;

            if (currentPlayer.isActive()) {
                char letter = 'z';
                int number = 0;
                getValidInput(&letter, &number, board);
                turnFaceUp(*board, static_cast<Letter>(letter), static_cast<Number>(number));
                Card *selectedCard = board->getCard(static_cast<Letter>(letter), static_cast<Number>(number));
                game.setCurrentCard(selectedCard);
            }
            if (!rules.isValid(game)) {
                if (game.twoCardsSelected()) {
                    game.setPlayersActive(false);
                }
            }
            if (game.twoCardsSelected()) {
                game.clearSelectedCards();
            }
            cout << game << endl;
        }
        game.setRound(++round);
        awardActivePlayers(game);
    }
    printLeastToMostRubiesAndWinner(game);
}


int main() {
    //runGame();
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
