//
// Created by iDarkDuck on 2018-10-19.
//

#include "rules.h"

Rules::Rules(const int &nPlayers) : nPlayers(nPlayers), currentSide(0), walrusBlockValue("Z0") {}

bool Rules::isValid(const Game &game) {
    if (twoCardsSelected(game)) return (*game.getPreviousCard() == *game.getCurrentCard());
    return true;
}

bool Rules::twoCardsSelected(const Game &game) const {
    try { return (game.getPreviousCard() != nullptr && game.getCurrentCard() != nullptr); }
    catch (...) { return false; }
}

bool Rules::gameOver(const Game &game) { return game.getRound() >= 7; }

bool Rules::roundOver(const Game &game) {
    int nActivePlayers = 0;
    for (int i = 0; i < nPlayers; i++) {
        auto player = getNextPlayer(game);
        if (player.isActive()) { nActivePlayers++; }
    }
    if (nActivePlayers == 1) walrusBlockValue = "Z0";
    return nActivePlayers == 1;
}

const Player &Rules::getNextPlayer(const Game &game) {
    const Game *gamePtr = &game;
    const Player &player = const_cast<Game *>(gamePtr)->getPlayer(sides[currentSide++]);
    if (currentSide >= nPlayers) currentSide = 0;
    return player;
}

void Rules::expertRules(Game &game, int &sideCounter) {
    Letter letter = Z;
    Number number = Zero;
    while (true) {
        game.getCard(letter, number, Walrus);
        if (convertToString(letter, number) == walrusBlockValue) cout << "Selected Card blocked by walrus" << endl;
        else break;
    }
    Card *selectedCard = game.getCard(letter, number);
    game.setCard(letter, number, selectedCard);
    game.setCurrentCard(selectedCard);
    expertRulesHandler(selectedCard, game, letter, number, sideCounter);
    cout << game << endl;
}

void Rules::expertRulesHandler(Card *card, Game &game, Letter &letter, Number &number, int &sideCounter) {
    switch (card->getAnimal()) {
        case 'O':
            expertOctopus(card, game, letter, number);
            break;
        case 'P':
            expertPenguin(game, sideCounter);
            break;
        case 'C':
            expertCrab(card, game, letter, number, sideCounter);
            break;
        case 'W':
            expertWalrus(game);
            break;
        default:
            expertTurtle(sideCounter);
            break;
    }
}

void Rules::expertOctopus(Card *card, Game &game, Letter &letter, Number &number) {
    cout << "You have picked an Octopus!" << endl;
    string pick = "Pick position with an adjacent card in the same (row or column) to swap: ";
    cout << pick << endl;
    Letter _letter = Z;
    Number _number = Zero;
    while (true) {
        game.getCard(_letter, _number, Octopus);
        if (!(_letter == letter || number == _number)) cout << "Invalid Card! " + pick << endl; else break;
    }
    game.expertRules(_letter, _number, letter, number, Octopus, card);
}

string Rules::convertToString(const Letter &l, const Number &n) { return (LetterToChar(l) + to_string(n)); }

char Rules::LetterToChar(const Letter &_letter) {
    if (_letter == A) { return 'A'; }
    else if (_letter == B) { return 'B'; }
    else if (_letter == C) { return 'C'; }
    else if (_letter == D) { return 'D'; }
    else if (_letter == E) { return 'E'; }
    return 'Z';
}

void Rules::expertPenguin(Game &game, int &sideCounter) {
    cout << "You have picked a Penguin!" << endl;
    cout << "Pick a card to change face up or face down: " << endl;
    game.expertRules(Z, Zero, Z, Zero, Octopus, nullptr);
}

void Rules::expertWalrus(Game &game) {
    cout << "You have picked a Walrus!" << endl;
    cout << "Pick a card to block from being chosen in the next round:" << endl;
    Letter someLetter = Z;
    Number someNumber = Zero;
    game.getCard(someLetter, someNumber, Walrus);
    walrusBlockValue = LetterToChar(someLetter) + to_string(someNumber);
}

void Rules::expertCrab(Card *card, Game &game, Letter &letter, Number &number, int &sideCounter) {
    Player &player = game.getPlayer(sides[sideCounter]);
    cout << "You have picked a Crab!" << endl;
    cout << *card << endl;
    cout << "Pick another card. If it doesn't match, you lose the round:" << endl;
    Letter _letter = Z;
    Number _number = Zero;
    Card *selectedCard;
    while (true) {
        cout << *(selectedCard = game.getCard(_letter, _number, Crab)) << endl;
        if (selectedCard->getColor() == card->getColor() && selectedCard->getAnimal() == card->getAnimal()) {
            cout << "This is the card you just picked. Choose another" << endl;
        } else break;
    }
    cout << player.getName() + " picked:" << endl;
    if (selectedCard->getColor() != card->getColor() && selectedCard->getAnimal() != card->getAnimal()) {
        cout << "The cards didn't match :( " + player.getName() + " is out of the current round." << endl;
        player.setActive(false);
    } else { cout << "The cards matched :) " + player.getName() + " is still in the current round." << endl; }
}

void Rules::expertTurtle(int &sideCounter) {
    cout << "You have picked a Turtle!" << endl;
    cout << "Skipping next player's turn." << endl;
    sideCounter = (sideCounter + 1) % nPlayers;
}