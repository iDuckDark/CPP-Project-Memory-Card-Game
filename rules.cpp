//
// Created by iDarkDuck on 2018-10-19.
//

#include "rules.h"

Rules::Rules(int nPlayers) : nPlayers(nPlayers), currentSide(0) {}

bool Rules::isValid(const Game &game) {
    if (twoCardsSelected(game)) { return (*game.getPreviousCard() == *game.getCurrentCard()); }
    return true;
}

bool Rules::twoCardsSelected(const Game &game) const {
    try { return (game.getPreviousCard() != nullptr && game.getCurrentCard() != nullptr); }
    catch (...) { return false; }
}

bool Rules::gameOver(const Game &game) { return game.getRound() >= 7; }

//TODO Fix error
bool Rules::roundOver(const Game &game) {
//    Game g = game;
//    int nActivePlayers = 0;
//    for (int i = 0; i < nPlayers; i++) {
//        auto player = getNextPlayer(g);
//        if (player.isActive()) { nActivePlayers++; }
//    }
//    return nActivePlayers;
    return game.getNActivePlayers() == 1;
}

const Player &Rules::getNextPlayer(Game &game) {
    const Player &p = game.getPlayer(sides[currentSide++]);
    if (currentSide >= nPlayers) { currentSide = 0; }
    return p;
}

void Rules::expertRules(Card *card, Game &game, Letter &letter, Number &number, const Side &side,
                        std::map<std::string, Card *> *cardMap, bool *skip, string *walrus) {
    switch (card->getAnimal()) {
        case 'O':
            expertOctopus(card, game, letter, number, side, cardMap);
            break;
        case 'P':
            expertPenguin(card, game, letter, number, side, cardMap);
            break;
        case 'C':
            expertCrab(card, game, letter, number, side);
            break;
        case 'W':
            expertWalrus(card, game, letter, number, side, walrus);
            break;
        default:
            expertTurtle(card, game, letter, number, side, skip);
            break;
    }
}

void Rules::expertOctopus(Card *card, Game &game, Letter &letter, Number &number, const Side &side,
                          map<string, Card *> *cardMap) {
    cout << "You have picked an Octopus!" << endl;
    cout << "Pick position with an adjacent card in the same row or the same column to swap: " << endl;

    //TODO Get input and implement logic

    Letter _letter = Z;
    Number _number = Zero;
    game.getValidInputExpertOct(&_letter, &_number);
    while (!(_letter == letter || number == _number)) {
        cout << "Incorrect Card! Pick position with an adjacent card in the same row or the same column to swap: "
             << endl;
        game.getValidInputExpertOct(&_letter, &_number);
    }
    Card *selectedCard = game.getCard(_letter, _number);

    //SWAPPING HERE
    //Swap map - Peter

    //card to be swapped with (second card)
    char cara = 'Z';
    if (_letter == A) { cara = 'A'; }
    else if (_letter == B) { cara = 'B'; }
    else if (_letter == C) { cara = 'C'; }
    else if (_letter == D) { cara = 'D'; }
    else if (_letter == E) { cara = 'E'; }
    //current card
    char cara2 = 'Z';
    if (letter == A) { cara2 = 'A'; }
    else if (letter == B) { cara2 = 'B'; }
    else if (letter == C) { cara2 = 'C'; }
    else if (letter == D) { cara2 = 'D'; }
    else if (letter == E) { cara2 = 'E'; }

    //if the second card is already face up
    if (cardMap->count(cara + to_string(_number))) {
        cout << cara + to_string(_number) << endl;
        Card *temp = card;
        card = selectedCard;
        selectedCard = temp;
        //swap hashes
        cardMap->operator[](cara + to_string(_number)) = selectedCard;
        cardMap->operator[](cara2 + to_string(number)) = card;

    } else {//swapping with faced down card
        map<string, Card *>::iterator it = (*cardMap).find(cara2 + to_string(number));
        cardMap->erase(it);
        Card *temp = card;
        card = selectedCard;
        selectedCard = temp;
        //hashed to new location
        cardMap->operator[](cara + to_string(_number)) = selectedCard;

        //need to set new location to face up and old location to face down --nevin
        game.swapCards(letter, number, _letter, _number); //Expert Octopus
    }

    // When an octopus card is turned over, the
    //card is exchanging position with an adjacent card in the same row or the same column (4-neighbourhood)
    //The adjacent card may be face up or down and will remain unchanged.
}

void Rules::expertPenguin(Card *card, Game &game, Letter &letter, Number &number, const Side &side,
                          map<string, Card *> *cardMap) {
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

void Rules::expertWalrus(Card *card, Game &game, Letter &letter, Number &number, const Side &side, string *walrus) {
    cout << "You have picked a Walrus!" << endl;
    cout << "Pick a card to block from being chosen in the next round:" << endl;
    Letter someLetter = Z;
    Number someNumber = Zero;
    //TODO Get input and implement logic
    game.getValidInputExpert(&someLetter, &someNumber);
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
    *walrus = cara + to_string(someNumber);
}

void Rules::expertCrab(Card *card, Game &game, Letter &letter, Number &number, const Side &side) {
    Player &player = game.getPlayer(side);
    cout << "You have picked a Crab!" << endl;
    cout << *card << endl;
    cout << "Pick another card. If it doesn't match, you lose the round:" << endl;
    Letter _letter = Z;
    Number _number = Zero;
    game.getValidInputExpert(&_letter, &_number);
    Card *selectedCard = game.getCard(_letter, _number);
    cout << *selectedCard << endl;
    while (selectedCard->getColor() == card->getColor() && selectedCard->getAnimal() == card->getAnimal()) {
        cout << "This is the card you just picked. Choose another" << endl;
        game.getValidInputExpert(&_letter, &_number);
        selectedCard = game.getCard(_letter, _number);
    }
    cout << "You picked:" << endl;
    cout << *selectedCard << endl;
    if (selectedCard->getColor() != card->getColor() && selectedCard->getAnimal() != card->getAnimal()) {
        cout << "The cards didn't match :( " + player.getName() + " is out of the current round." << endl;
        player.setActive(false);
    } else {
        cout << "The cards matched :) " + player.getName() + " is still in the current round." << endl;
    }
}

void Rules::expertTurtle(Card *card, Game &game, Letter &letter, Number &number, const Side &side, bool *skip) {
    Player &player = game.getPlayer(side);
    cout << "You have picked a Turtle!" << endl;
    cout << "Skipping next player's turn." << endl;
    *skip = true;
    //TODO Get input and implement logic
    //. Finally,
    //with the turtle the next player in the current round is skipped, i.e., the next player will not turn over a card
    //and will not lose in the next step.
}