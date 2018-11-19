//
// Created by iDarkDuck on 2018-10-19.
//

#include "rules.h"

bool Rules::isValid(const Game &game) {
    //TODO remove cout once game is complete (Debugging purpose)
    cout << endl << "TEST RULES IS VALID? " << endl;
    if (game.twoCardsSelected()) {
        cout << "Previous & Next card Equal? " << (*game.getPreviousCard() == *game.getCurrentCard()) << endl
             << *game.getPreviousCard() << endl << *game.getCurrentCard() << endl;
        return (*game.getPreviousCard() == *game.getCurrentCard());
    }
    cout << "NO TWO CARDS SELECTED" << endl << endl;
    return false;
}

bool Rules::gameOver(const Game &game) { return game.getRound() >= 7; }

bool Rules::roundOver(const Game &game) { return game.getNActivePlayers() == 1; }


void Rules::expertRules(Card *card, Game &game, Letter &letter, Number &number, const Side &side,
                        std::map<std::string, Card *> *cardMap,bool* skip) {
    switch (card->getAnimal()) {
        case '0':
            expertOctopus(card, game, letter, number, side);
            break;
        case 'P':
            expertPenguin(card, game, letter, number, side, cardMap);
            break;
        case 'C':
            expertCrab(card, game, letter, number, side);
            break;
        case 'W':
            expertWalrus(card, game, letter, number, side);
            break;
        default:
            expertTurtle(card, game, letter, number, side, skip);
            break;
    }
}

void Rules::expertOctopus(Card *card, Game &game, Letter &letter, Number &number, const Side &side) {
    cout << "You have picked an Octopus!" << endl;
    cout << "Pick position with an adjacent card in the same row or the same column to swap: " << endl;

    //TODO Get input and implement logic

    // When an octopus card is turned over, the
    //card is exchanging position with an adjacent card in the same row or the same column (4-neighbourhood)
    //The adjacent card may be face up or down and will remain unchanged.
}

void Rules::expertPenguin(Card *card, Game &game, Letter &letter, Number &number, const Side &side,
                          std::map<std::string, Card *> *cardMap) {
    Player &player = game.getPlayer(side);
    cout << "You have picked a Penguin!" << endl;
    cout << "Pick a card to change face up or face down: " << endl;
    Letter someLetter = Z;
    Number someNumber = Zero;
    string input;
    while (true) {
        cin >> input;
        if (input.length() == 2) break;
        else cout << "Invalid input, please try again: ";
    }
    someLetter = static_cast<Letter>(toEnum(input[0]));
    someNumber = static_cast<Number>(toEnum(input[1]));

    Card *selectedCard = game.getCard(someLetter, someNumber);
    char cara = 'Z';
    if (someLetter == A) {
        cara = 'A';
    } else if (someLetter == B) {
        cara = 'B';
    } else if (someLetter == C) {
        cara = 'C';
    } else if (someLetter == D) {
        cara = 'D';
    } else if (someLetter == E) {
        cara = 'E';
    }
    if (cardMap->count(cara + to_string(someNumber))) {

        cout << "Turning Face down :" << endl;
        cardMap->erase(cara + to_string(someNumber));
        //TODO need to make card face down from game->
    } else {
        cout << "Turning Face Up:" << endl;
        cardMap->operator[](cara + to_string(someNumber)) = selectedCard;
        game.setCurrentCard(selectedCard);
    }
    cout << *selectedCard << endl;
}

void Rules::expertWalrus(Card *card, Game &game, Letter &letter, Number &number, const Side &side) {
    cout << "You have picked a Walrus!" << endl;
    cout << "Pick a card to block from being chosen in the next round:" << endl;
    //TODO Get input and implement logic
}

void Rules::expertCrab(Card *card, Game &game, Letter &letter, Number &number, const Side &side) {
    Player &player = game.getPlayer(side);
    cout << "You have picked a Crab!" << endl;
    cout << *card << endl;
    cout << "Pick another card. If it doesn't match, you lose the round:" << endl;
    Letter someLetter = Z;
    Number someNumber = Zero;
    game.getValidInput(&someLetter, &someNumber);
    Card *selectedCard = game.getCard(someLetter, someNumber);

    cout << "You picked:" << endl;
    cout << *selectedCard << endl;

    if (selectedCard->getColor() != card->getColor() && selectedCard->getAnimal() != card->getAnimal()) {
        cout << "The cards didn't match :( " + player.getName() + " is out of the current round." << endl;
        player.setActive(false);
    } else {
        cout << "The cards matched :) " + player.getName() + " is still in the current round." << endl;
    }
}

void Rules::expertTurtle(Card *card, Game &game, Letter &letter, Number &number, const Side &side, bool* skip) {
    Player &player = game.getPlayer(side);
    cout << "You have picked a Turtle!" << endl;
    cout << "Skipping next player's turn." << endl;
    *skip = true;
    //TODO Get input and implement logic
    //. Finally,
    //with the turtle the next player in the current round is skipped, i.e., the next player will not turn over a card
    //and will not lose in the next step.
}