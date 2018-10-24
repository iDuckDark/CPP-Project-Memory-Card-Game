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

void temporaryRevealThreeCards(Board &board, Player &player) {
    cout << "Three random cards are revealed temporary in front of the players" << endl;
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
    cout << board << endl;
    pause();

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
    cout << board << endl;
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

void awardActivePlayers(vector<Player> &players) {
    for (int i = 0; i < players.size(); i++) {
        if (players[i].isActive()) {
            srand(time(NULL));
            int randomRubies = (rand() % 4); //TODO is it random reward of 1 to 4???
            Reward reward(randomRubies);
            players[i].addReward(reward);
        }
    }
}

//https://stackoverflow.com/questions/29676147/sorting-a-vector-of-classes-based-on-a-variable-in-the-class
bool compareRewards(const Reward &r1, const Reward &r2) {
    return r1.getNRubies() < r2.getNRubies();
}

void printLeastToMostRubiesAndWinner(vector<Player> players) {
    //TODO Sort them using a vector operator method
    //sort(players.begin(), players.end(), compareRewards(players.begin().));
    set<pair<int, string> > playersSet;
    for (int i = 0; i < players.size(); i++) {
        playersSet.insert({players[i].getNRubies(), players[i].getName()});
    }
    int winCounter = 0;
    for (set<pair<int, string>>::iterator i = playersSet.begin(); i != playersSet.end(); i++) {
        pair<int, string> element = *i;
        if (winCounter == players.size() - 1) {
            cout << "Winner : ";
        }
        cout << "Name: " << element.second << ", nRubies: " << element.first << endl;
        winCounter++;
    }
//    Player winner = players[players.size() - 1];
//    for (int i = 0; i < players.size(); i++) {
//        if (i == players.size() - 1) {
//            cout << "Winner is :" << endl;
//        }
//        cout << players[i] << endl;
//    }
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
    Board board = game.getBoard();
    //TODO getPlayer() which gets the current player
    vector<Player> players = game.getPlayers();
    while (!rule.gameOver(game)) {
        board.reset();
        game.setAllPlayersActive();
        //TODO getPlayer() which gets the current player
        Player currentPlayer = game.getPlayer();
        temporaryRevealThreeCards(board, currentPlayer);
        while (!rule.roundOver(game)) {
            for (int i = 0; i < nPlayers; i++) {
                if (players[i].isActive()) {
                    cout << "Pick a letter from A-E";
                    char letter = 'z';
                    while (letter != 'A' && letter != 'B' && letter != 'C' && letter != 'D' && letter != 'E') {
                        cin >> letter;
                    }
                    cout << "Pick a number from 1-5";
                    int number = 0;
                    while (((number != One && number != Two && number != Three && number != Four && number != Five) &&
                            letter == 'C') ||
                           (number != One && number != Two && number != Four && number != Five)) {
                        cin >> number;
                    }
                    turnFaceUp(board, letter, number);
                    cout << board << endl;
                }
                if (!rule.isValid(game)) {
                    players[i].setActive(false);
                }
                cout << board;
            }
        }
        awardActivePlayers(players);
    }
    //TODO SET END OF GAME TO PLAYERS;
    printLeastToMostRubiesAndWinner(players);
}

int main() {
    //runGame();

    Board board;
    //cout << board << endl;
    board.turnFaceUp(A, Two);
    Player peter{"Peter", "top", 1};
    temporaryRevealThreeCards(board, peter);
    //cout << board << endl;

    cout << "No Errors" << endl;
    return 0;
}


//vector<int> generateRandomNumbers() {
//    srand(time(NULL));
//    vector<int> randomVector;
//    while (true) {
//        int random_letter = (rand() % 5) + 0;
//        if (random_letter != 2) {
//            //cout << random_letter << endl;
//            randomVector.push_back(random_letter);
//            break;
//        }
//    }
//    while (true) {
//        int random_letter2 = (rand() % 5) + 0;
//        if (random_letter2 != randomVector[0] && random_letter2 != 2) {
//            //cout << random_letter2 << endl;
//            randomVector.push_back(random_letter2);
//            break;
//        }
//    }
//    while (true) {
//        int random_letter3 = (rand() % 5) + 0;
//        if (random_letter3 != randomVector[0] && random_letter3 != randomVector[1] && random_letter3 != 2) {
//            //cout << random_letter3 << endl;
//            randomVector.push_back(random_letter3);
//            break;
//        }
//    }
//
//    //Old random code DO NOT DELETE
//    //Letter letters[] = {A, B, C, D, E};
//    //Number numbers[] = {One, Two, Three, Four, Five};
//    vector<int> randomIndexLetters = generateRandomNumbers();
//    vector<int> randomIndexNumbers = generateRandomNumbers();
//    for (int i = 0; i < 3; i++) {
//        board.turnFaceUp(letters[randomIndexLetters[i]], numbers[randomIndexNumbers[i]]);
//    }
//    cout << board << endl;
//    pause();
//    for (int i = 0; i < 3; i++) {
//        board.turnFaceDown(letters[randomIndexLetters[i]], numbers[randomIndexNumbers[i]]);
//    }
//    //cout << board << endl;
//    return randomVector;
//}
