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
        cin >> mode;
        if (mode != 1 && mode != 2) {
            cout << "Invalid input, please try again: ";
        } else break;
    }
}

void temporaryRevealThreeCards(Game &game, const int &mode) {
    cout << "Three random cards are revealed temporary in front of the players" << endl;
    Board *board = &game.getBoard();
    for (int i = 0; i < game.getNPlayers(); i++) {
        const Player &player = game.getPlayer();
        const Side &side = player.getSide();
        switch (side) {
            case Top:
                board->turnFaceUp(A, Two);
                board->turnFaceUp(A, Three);
                board->turnFaceUp(A, Four);
                break;
            case Bottom :
                board->turnFaceUp(E, Two);
                board->turnFaceUp(E, Three);
                board->turnFaceUp(E, Four);
                break;
            case Right:
                board->turnFaceUp(B, One);
                board->turnFaceUp(C, One);
                board->turnFaceUp(D, One);
                break;
            case Left:
                board->turnFaceUp(B, Five);
                board->turnFaceUp(C, Five);
                board->turnFaceUp(D, Five);
                break;
            default:
                break;
        }
    }
    if (mode == 1) {
        cout << game << endl;
    }
    cout << "Cards are hidden now" << endl;
}

void getValidInput(Letter *letter, Number *number, Board *board) {
    while (true) {
        string input;
        cout << "Pick a card from (A to E) and from (1 to 5): ";
        while (true) {
            cin >> input;
            if (input.length() == 2) break;
            else cout << "Invalid input, please try again: ";
        }
        *letter = static_cast<Letter>(toEnum(input[0]));
        *number = static_cast<Number>(toEnum(input[1]));
        try {
            if (!board->isFaceUp(*letter, *number)) break;
            else cout << "Card is already faced up! " << endl;
        } catch (const std::exception &exc) {
            cout << "Invalid Card Selected, please try again" << endl;
            cerr << exc.what() << endl;
        }
    }
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
    for (const auto &player : players) {
        if (winCounter == players.size()) {
            cout << "Winner : ";
        }
        winCounter++;
        cout << player.getName() << " with Rubies: " << player.getNRubies() << endl;
    }
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
    int mode = 0;
    setMode(mode);

    cout << "Number of Players " << "(Minimum 2 - Maximum 4) : ";
    int nPlayers = 0;
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

                    Letter letter = Z;
                    Number number = Zero;
                    getValidInput(&letter, &number, board);
                    board->turnFaceUp(letter, number);
                    Card *selectedCard = board->getCard(letter, number);
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
    }

    else if (mode == 2) {
        std::map<std::string, Card *> cardMap;
//
//        //if expertMode
        int round = 1;
        while (!rules.gameOver(game)) {
            cout << "Expert Mode" << endl;
            board->reset();
            game.setAllPlayersActive();
            temporaryRevealThreeCards(game, mode);
            board->reset();
            while (!rules.roundOver(game)) { //{Peter , Nevin, Divyang }
                Player &currentPlayer = game.getPlayer(); // , Nevin, Divyang, Peter  but now is Peter
                cout << "Round: " << round << " , Turn: " << currentPlayer.getName() << endl;
                if (currentPlayer.isActive()) {
                    Letter letter = Z;
                    Number number = Zero;
                    getValidInput(&letter, &number, board);
                    board->turnFaceUp(letter, number);
                    Card *selectedCard = board->getCard(static_cast<Letter>(letter), static_cast<Number>(number));
                    rules.expertRules(selectedCard, game, static_cast<Letter>(letter), static_cast<Number>(number));
                    char cara='Z';
                    if(letter == A){
                        cara =  'A';
                    }else if (letter == B){
                        cara =  'B';
                    }else if (letter == C){
                        cara =  'C';
                    }else if (letter == D){
                        cara =  'D';
                    }else if (letter == E){
                        cara =  'E';
                    }
                    cardMap[cara + to_string(number)] = selectedCard;
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
    runGame();
//    Game game;
//   Board *board = &game.getBoard();
//    cout << *board << endl;
//    Letter letter = Z;
//    Number number = Zero;
//    getValidInput(&letter, &number, board);
//    board->turnFaceUp(letter, number);
//    cout << *board << endl;
    return 0;
}

