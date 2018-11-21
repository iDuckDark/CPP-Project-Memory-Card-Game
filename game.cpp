//
// Created by iDarkDuck on 2018-10-19.
//

#include "game.h"

Game::Game(int &mode, int &nPlayers) : nRound(1), currentSide(Top) {
    setMode(mode);
    createPlayers(nPlayers);
    makeCardDeck();
    reset();
}

void Game::setMode(int &mode) {
    cout << "Please choose your game version:" << endl;
    cout << "Enter 1 for Base Mode and 2 for Expect Mode: ";
    while (true) {
        char input;
        cin >> input;
        mode = ((int) input - 48);
        if (mode == 1 || mode == 2) break;
        else cout << "Invalid input, please try again: ";
    }
    this->mode = mode;
}

void Game::createPlayers(int &nPlayers) {
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
    const vector<Side> sides = {Top, Bottom, Left, Right};
    for (int i = 0; i < nPlayers; i++) {
        Player player{names[i]};
        player.setSide(sides[i]);
        addPlayer(player);
    }
}

void Game::makeCardDeck() {
    CardDeck &deck = CardDeck::make_CardDeck();
    int i = 1, j = 1;
    while (!deck.isEmpty()) {
        setCard(static_cast<Letter>(i), static_cast<Number>(j++), deck.getNext());
        if (j == 5) {
            j = 0;
            i++;
        }
    }
}

void Game::nextRound() {
    ++nRound;;
    awardActivePlayers();
    reset();
}


int Game::getRound() const { return nRound; }

void Game::addPlayer(const Player &player) {
    players.push_back(player);
    vector<const Card *> cardVector;
    cards.push_back(cardVector);
}

void Game::setSide(Side side) { currentSide = side; }

Player &Game::getPlayer(Side side) {
    for (auto &player: players) {
        if (player.getSide() == side) {
            setSide(side);
            return player;
        }
    }
    throw out_of_range("Invalid Player");
}

const Card *Game::getPreviousCard() const {
    vector<const Card *> cardVector = cards[currentSide];
    if (cardVector.size() == 0) { throw new out_of_range("No previous card selected!"); }
    const Card *previousCard = cardVector[0];
    return previousCard;
}

const Card *Game::getCurrentCard() const {
    vector<const Card *> cardVector = cards[currentSide];
    if (cardVector.size() <= 1) { throw new out_of_range("No current card selected!"); }
    const Card *currentCard = cardVector[1];
    return currentCard;
}

void Game::setCurrentCard(const Card *card) {
    if (card != nullptr) {
        vector<const Card *> &cardVector = cards[currentSide];
        cardVector.push_back(card);
    } else if (card == nullptr && cards[currentSide].size() != 0) {
        clearSelectedCards();
    }
}

void Game::clearSelectedCards() {
    vector<const Card *> &cardVector = cards[currentSide];
    cardVector.pop_back();
    cardVector.pop_back();
}

void Game::reset() {
    setAllPlayersActive();
    if (mode == 1) temporaryRevealThreeCards();
    cout << "Cards are hidden now" << endl;
    board.reset();
    if (mode == 2) { cardMap.clear(); }
}

void Game::setAllPlayersActive() {
    for (auto &player: players) { player.setActive(true); }
}

int Game::getNActivePlayers() const {
    int nActive = 0;
    for (auto player: players) { if (player.isActive()) nActive++; }
    return nActive;
}

void Game::temporaryRevealThreeCards() {
    cout << "Three random cards are revealed temporary in front of the players" << endl;
    for (const auto &player: players) {
        switch (player.getSide()) {
            case Top:
                for (int i = 0; i < 3; i++) board.turnFaceUp(A, Number(Two + i));
                break;
            case Bottom :
                for (int i = 0; i < 3; i++) board.turnFaceUp(E, Number(Two + i));
                break;
            case Left:
                for (int i = 0; i < 3; i++) board.turnFaceUp(Letter(B + i), One);
                break;
            default:
                for (int i = 0; i < 3; i++) board.turnFaceUp(Letter(B + i), Five);
                break;
        }
    }
    cout << (*this) << endl;
}

bool Game::isValidCard(const Letter &letter, const Number &number) const { return board.isValidCard(letter, number); }

bool Game::isBlocked(const Letter &letter, const Number &number) const { return board.isBlocked(letter, number); }

void Game::setBlocked(const Letter &letter, const Number &number) { board.setBlocked(letter, number); }

void Game::setCard(const Letter &letter, const Number &number, Card *card) {
    board.setCard(letter, number, card);
//    else if (ready && mode == 2) {
//        cardMap[convertToString(letter, number)] = card;
//    }
}

string Game::convertToString(const Letter &letter, const Number &number) {
    char cara = 'Z';
    if (letter == A) { cara = 'A'; }
    else if (letter == B) { cara = 'B'; }
    else if (letter == C) { cara = 'C'; }
    else if (letter == D) { cara = 'D'; }
    else if (letter == E) { cara = 'E'; }
    return (cara + to_string(number));
}

Card *Game::getCard(const Letter &letter, const Number &number) {
    Letter let = letter;
    Number num = number;
    if (mode == 1) { getValidInput(&let, &num); }
    board.turnFaceUp(let, num);
    return board.getCard(let, num);
}

void Game::getValidInput(Letter *letter, Number *number) {
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
            if (!board.isFaceUp(*letter, *number)) break;
            else cout << "Card is already faced up! " << endl;
        } catch (const exception &exc) {
            cout << "Invalid Card Selected, please try again" << endl;
            cerr << exc.what() << endl;
        }
    }
}

void Game::getValidInputExpert(Letter *letter, Number *number) {
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
            if (!board.isFaceUp(*letter, *number)) break;
            else cout << "Card is already faced up! " << endl;
        } catch (const exception &exc) {
            cout << "Invalid Card Selected, please try again" << endl;
            cerr << exc.what() << endl;
        }
    }
}

void Game::getValidInputExpertOct(Letter *letter, Number *number) {
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
            if (isValidCard(*letter, *number)) break;
            else cout << "Card is not valid! " << endl;
        } catch (const exception &exc) {
            cout << "Invalid Card Selected, please try again" << endl;
            cerr << exc.what() << endl;
        }
    }
}

void Game::awardActivePlayers() {//TODO rewarddeck pointer?
    for (auto &player: players)if (player.isActive() && !rewardDeck.isEmpty())player.addReward(*rewardDeck.getNext());
}

ostream &operator<<(ostream &os, const Game &game) {
    if (game.mode == 1 && game.getRound() < 7) {
        os << game.board << endl;
        for (const auto &player: game.players) { os << player << endl; }
    }
    //else if (game.mode == 2) { game.expertModePrint(); }
    else game.printLeastToMostRubiesAndWinner();
    return os;
}

void Game::swapCards(const Letter &l1, const Number &n1, const Letter &l2, const Number &n2) {
    board.swapCards(l1, n1, l2, n2);
}

void Game::printLeastToMostRubiesAndWinner() const {
    vector<Player> playerS = players;
    for (auto &player: playerS) { player.setDisplayMode(true); }
    int winCounter = 1;
    sort(playerS.begin(), playerS.end());
    for (auto &player : playerS) {
        if (winCounter == playerS.size()) { cout << "Winner : "; }
        winCounter++;
        cout << player.getName() << " with Rubies: " << player.getNRubies() << endl;
        player.setDisplayMode(false);
    }
}

void Game::expertModePrint() const {
    for (int i = 0; i < 3; i++) {
        for (auto const&[key, val] : cardMap) { cout << (*val)(i) << " "; }
        cout << endl;
    }
    for (auto const &card : cardMap) { cout << card.first << "  "; }
    cout << endl;
}

map<string, Card *> &Game::getCardMap() { return cardMap; }