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

void printLeastToMostRubiesAndWinner(Game &game) {
    vector<Player> players;
    for (int i = 0; i < game.getNPlayers(); i++) {
        Player &player = game.getPlayer(static_cast<Side>(i));
        player.setDisplayMode(true);
        players.push_back(player);
    }
    int winCounter = 1;
    sort(players.begin(), players.end());
    for (const auto &player : players) {
        if (winCounter == players.size()) { cout << "Winner : "; }
        winCounter++;
        cout << player.getName() << " with Rubies: " << player.getNRubies() << endl;
    }
}

void expertModePrint(std::map<std::string, Card *> cardMap) {
    for (int i = 0; i < 3; i++) {
        for (auto const&[key, val] : cardMap) {
            cout << (*val)(i) + " ";
        }
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
    const vector<Side> sides = {Top, Bottom, Left, Right};
    createPlayers(game, nPlayers, sides);
    Rules rules;
    //TODO CardDeck IN MAIN using SET CARD
//    CardDeck &deck = CardDeck::make_CardDeck();
//    while (!deck.isEmpty()) { cards.push_back(deck.getNext()); }

    if (mode == 1) {
        int round = 1;
        while (!rules.gameOver(game)) {
            game.reset(mode);
            int sideCounter = 0;
            while (!rules.roundOver(game)) {
                Player &currentPlayer = game.getPlayer(sides[sideCounter++]);
                if (sideCounter >= nPlayers) { sideCounter = 0; }
                cout << "Round: " << round << " , Turn: " << currentPlayer.getName() << endl;
                if (currentPlayer.isActive()) {
                    Letter letter = Z;
                    Number number = Zero;
                    game.getValidInput(&letter, &number);
                    Card *selectedCard = game.getCard(letter, number);
                    game.setCurrentCard(selectedCard);
                    game.setCard(letter, number, selectedCard);
                }
                if (!rules.isValid(game)) { if (game.twoCardsSelected()) { currentPlayer.setActive(false); }}
                if (game.twoCardsSelected()) { game.clearSelectedCards(); }
                cout << game << endl;
            }
            game.setRound(++round);
            game.awardActivePlayers();
        }
        printLeastToMostRubiesAndWinner(game);
    } else if (mode == 2) {
        std::map<std::string, Card *> cardMap;
        int round = 1;
        while (!rules.gameOver(game)) {
            //cout << "Expert Mode" << endl;
            game.reset(mode);
            int sideCounter = 0;
            bool *skipTurn = new bool(false);
            while (!rules.roundOver(game)) {
                //to skip a turn do side++
                if (*skipTurn) sideCounter++;
                const Side &side = sides[sideCounter++];
                *skipTurn = false;
                Player &currentPlayer = game.getPlayer(side);
                if (sideCounter >= nPlayers) { sideCounter = 0; }
                cout << "Round: " << round << " , Turn: " << currentPlayer.getName() << endl;
                if (currentPlayer.isActive()) {
                    Letter letter = Z;
                    Number number = Zero;
                    game.getValidInput(&letter, &number);
                    Card *selectedCard = game.getCard(letter, number);
                    rules.expertRules(selectedCard, game, letter, number, side, &cardMap, skipTurn);
                    char cara = 'Z';
                    if (letter == A) {
                        cara = 'A';
                    } else if (letter == B) {
                        cara = 'B';
                    } else if (letter == C) {
                        cara = 'C';
                    } else if (letter == D) {
                        cara = 'D';
                    } else if (letter == E) {
                        cara = 'E';
                    }
                    cardMap[cara + to_string(number)] = selectedCard;
                    expertModePrint(cardMap);
                    game.setCurrentCard(selectedCard);
                }
                if (!rules.isValid(game)) {
                    if (game.twoCardsSelected()) { currentPlayer.setActive(false); }
                }
                if (game.twoCardsSelected()) { game.clearSelectedCards(); }
            }
            game.setRound(++round);
            game.awardActivePlayers();
        }
        printLeastToMostRubiesAndWinner(game);
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


//   Board *board = &game.getBoard();
//    cout << *board << endl;
//    Letter letter = Z;
//    Number number = Zero;
//    getValidInput(&letter, &number, board);
//    board->turnFaceUp(letter, number);
//    cout << *board << endl;
    return 0;
}

