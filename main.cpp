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


void temporaryRevealThreeCards(Game &game, int mode) {
    cout << "Three random cards are revealed temporary in front of the players" << endl;
    Board *board = &game.getBoard();
    for (int i = 0; i < game.getNPlayers(); i++) {
        Player player = game.getPlayer();
        Side side = player.getSide();
        switch (side) {
            case Top:
                board->turnFaceUp(A, Two);
                board->turnFaceUp(A, Three);
                board->turnFaceUp(A, Four);
            case Bottom :
                board->turnFaceUp(E, Two);
                board->turnFaceUp(E, Three);
                board->turnFaceUp(E, Four);
            case Right:
                board->turnFaceUp(B, One);
                board->turnFaceUp(C, One);
                board->turnFaceUp(D, One);
            case Left:
                board->turnFaceUp(B, Five);
                board->turnFaceUp(C, Five);
                board->turnFaceUp(D, Five);
        }
    }
    if (mode == 1) {
        cout << game << endl;
    }
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

void printLeastToMostRubiesAndWinner(Game &game) {
    vector<Player> players;
    for (int i = 0; i < game.getNPlayers(); i++) {
        Player &player = game.getPlayer();
        player.setDisplayMode(true);
        players.push_back(player);
    }
    int winCounter = 1;
    sort(players.begin(), players.end());
    for (auto player : players) {
        if (winCounter == players.size()) {
            cout << "Winner : ";
        }
        winCounter++;
        cout << player.getName() << " with Rubies: " << player.getNRubies() << endl;
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
    } while (!(board->isFaceDown(convert2Char(letter), *number - 1)));
}

void expertModePrint(std::map<std::string, Card *> cardMap) {
    //print cards
    for (int i = 0; i < 3; i++) {
        for (auto const&[key, val] : cardMap) {
            cout << (*val)(i) + " ";
        }
        cout << endl;
    }
    //print location
    for (auto const&[key, val] : cardMap) {
        cout << key + "  ";
    }
    cout << endl;
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
    vector<string> names(nPlayers);
    for (int i = 0; i < nPlayers; i++) {
        cout << "Enter name for Player number " << (i + 1) << ": ";
        cin >> names[i];
    }

    Game game;
    Side sides[4] = {Top, Bottom, Left, Right};
    for (int i = 0; i < nPlayers; i++) {
        Player player{names[i]};
        player.setSide(sides[i]);
        game.addPlayer(player);
    }
    Rules rules;
    Board *board = &game.getBoard();
    if (mode == 1) {
        //if normal mode
        int round = 1;
        while (!rules.gameOver(game)) {
            board->reset();
            game.setAllPlayersActive();
            temporaryRevealThreeCards(game, mode);
            board->reset();
            while (!rules.roundOver(game)) { //{Peter , Nevin, Divyang, Hansel }

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
                        game.setPlayerActive(false);
                    }
                }
                if (game.twoCardsSelected()) {
                    game.clearSelectedCards();
                }
                cout << game << endl;
            }
            game.setRound(++round);
            game.awardActivePlayers();
        }
        printLeastToMostRubiesAndWinner(game);
    } else if (mode == 2) {
        std::map<std::string, Card *> cardMap;

        //if expertMode
        int round = 1;
        while (!rules.gameOver(game)) {
            cout << "Expert Mode" << endl;
            board->reset();
            game.setAllPlayersActive();
            temporaryRevealThreeCards(game, mode);
            board->reset();
            while (!rules.roundOver(game)) { //{Peter , Nevin, Divyang }
                cout << "Expert Mode 2" << endl;


                Player &currentPlayer = game.getPlayer(); // , Nevin, Divyang, Peter  but now is Peter
                cout << "Round: " << round << " , Turn: " << currentPlayer.getName() << endl;

                if (currentPlayer.isActive()) {
                    char letter = 'z';
                    int number = 0;
                    getValidInput(&letter, &number, board);
                    turnFaceUp(*board, static_cast<Letter>(letter), static_cast<Number>(number));
                    Card *selectedCard = board->getCard(static_cast<Letter>(letter), static_cast<Number>(number));
                    rules.expertRules(selectedCard, game, static_cast<Letter>(letter), static_cast<Number>(number));

                    cardMap[letter + to_string(number)] = selectedCard;

                    expertModePrint(cardMap);
                    game.setCurrentCard(selectedCard);
                }
                if (!rules.isValid(game)) {
                    if (game.twoCardsSelected()) {
                        game.setPlayerActive(false);
                    }
                }
                if (game.twoCardsSelected()) {
                    game.clearSelectedCards();
                }

            }
            game.setRound(++round);
            game.awardActivePlayers();
        }
        printLeastToMostRubiesAndWinner(game);
    }
}


int main() {
    //runGame();
    return 0;
}

