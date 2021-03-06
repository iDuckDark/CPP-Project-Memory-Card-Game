//
// Created by iDarkDuck on 2018-10-19.
//

#include "game.h"

//#define TEST_GAME

Game::Game(int &sideCounter, int &nPlayers) : nRound(1), currentSide(Side::Top), sideCounter(sideCounter) {
    cout << endl << "Welcome to Nevin's and Peter's Memory Card Game Fall 2018" << endl;
    setMode();
    createPlayers(nPlayers);
    makeCardDeck(), makeRewardDeck();
    reset();
    ready = true;
    sideCounter = nPlayers - 1;
}

void Game::setMode() {
    cout << "Please choose your game version:" << endl;
    cout << "Enter 1 for Base Mode and 2 for Expect Mode: ";
    while (true) {
        char input;
        cin >> input;
        mode = ((int) input - 48);
        if (mode == 1 || mode == 2) break;
        else cout << "Invalid input, please try again: ";
    }
    if (mode == 2) walrusBlockValue = "Z0";
}

void Game::createPlayers(int &nPlayers) {
    cout << "Number of Players " << "(Minimum 2 - Maximum 4) : ";
    while (true) {
        char input;
        cin >> input;
        nPlayers = ((int) input - 48);
        if ((nPlayers < 2 || nPlayers > 4)) cout << "Invalid input, please try again: " << endl;
        else break;
    }
    vector<string> names(static_cast<unsigned long>(nPlayers));
    for (int i = 0; i < nPlayers; i++) {
        cout << "Enter name for Player number " << (i + 1) << ": ";
        cin >> names[i];
        Player player{names[i]};
        player.setSide(sides[i]);
        if (!containsPlayer(player)) addPlayer(player);
        else cout << "Player already added to Game!" << endl, --i;
    }
}

bool Game::containsPlayer(const Player &p) { return find(players.begin(), players.end(), p) != players.end(); }

void Game::makeCardDeck() {
    CardDeck &deck = CardDeck::make_CardDeck();
    int i = 1, j = 1;
    while (!deck.isEmpty()) {
        setCard(static_cast<Letter>(i), static_cast<Number>(j++), deck.getNext());
        if (j == 5) { j = 0, i++; }
    }
}

void Game::makeRewardDeck() {
    RewardDeck &deck = RewardDeck::make_RewardDeck();
    while (!deck.isEmpty()) rewardDeck.push_back(deck.getNext());
}

void Game::nextRound() {
    ++nRound;
    awardActivePlayers();
    if (nRound != 7) reset();
    int nActive = 0;
    for (const auto &player: players) if (player.isActive()) nActive++;
    if (nActive == 1) walrusBlockValue = "Z0";
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
    vector<const Card *> cardVector = cards[static_cast<int>(currentSide)];
    if (cardVector.empty()) { throw new out_of_range("No previous card selected!"); }
    const Card *previousCard = cardVector[0];
    return previousCard;
}

const Card *Game::getCurrentCard() const {
    vector<const Card *> cardVector = cards[static_cast<int>(currentSide)];
    if (cardVector.size() <= 1) { throw new out_of_range("No current card selected!"); }
    const Card *currentCard = cardVector[1];
    return currentCard;
}

void Game::setCurrentCard(const Card *card) {
    if (mode == 1) {
        if (card != nullptr) {
            vector<const Card *> &cardVector = cards[static_cast<int>(currentSide)];
            cardVector.push_back(card);
        } else if (card == nullptr && !cards[static_cast<int>(currentSide)].empty() &&
                   twoCardsSelected()) { clearSelectedCards(); }
    }
}

bool Game::twoCardsSelected() const {
    try { return (getPreviousCard() != nullptr && getCurrentCard() != nullptr); }
    catch (...) { return false; }
}

void Game::clearSelectedCards() {
    vector<const Card *> &cardVector = cards[static_cast<int>(currentSide)];
    cardVector.pop_back();
    cardVector.pop_back();
}

void Game::reset() {
    setAllPlayersActive();
    board.reset();
    if (mode == 1 && nRound == 1) temporaryRevealThreeCards();
    if (mode == 2) cardMap.clear();
    cout << "Cards are hidden now" << endl;
    board.reset();
}

void Game::setAllPlayersActive() { for (auto &player: players) { player.setActive(true); }}

void Game::temporaryRevealThreeCards() {
    cout << "Three random cards are revealed temporary in front of the players" << endl;
    for (const auto &player: players) {
        switch (player.getSide()) {
            case Side::Top:
                for (int i = 0; i < 3; i++) board.turnFaceUp(A, Number(Two + i));
                break;
            case Side::Bottom :
                for (int i = 0; i < 3; i++) board.turnFaceUp(E, Number(Two + i));
                break;
            case Side::Left:
                for (int i = 0; i < 3; i++) board.turnFaceUp(Letter(B + i), One);
                break;
            default:
                for (int i = 0; i < 3; i++) board.turnFaceUp(Letter(B + i), Five);
                break;
        }
    }
    cout << (*this) << endl;
}

void Game::setCard(const Letter &letter, const Number &number, Card *card) {
    if (!ready) board.setCard(letter, number, card);
    if (mode == 2) cardMap[convertToString(letter, number)] = card;
}

string Game::convertToString(const Letter &let, const Number &num) { return (LetterToChar(let) + to_string(num)); }

char Game::LetterToChar(const Letter &_letter) {
    if (_letter == A) return 'A';
    else if (_letter == B) return 'B';
    else if (_letter == C) return 'C';
    else if (_letter == D) return 'D';
    else if (_letter == E) return 'E';
    return 'Z';
}

Card *Game::getCard(const Letter &letter, const Number &number) {
    if (mode == 1) {
        Letter let = letter;
        Number num = number;
        getValidInput(&let, &num, Animals);
        board.turnFaceUp(let, num);
        return board.getCard(let, num);
    } else { getExpertRulesInput(); }
    return nullptr;
}

Card *Game::getExpertCard(Letter &let, Number &num, const FaceAnimal &animal) {
    if (animal == Walrus || animal == Crab) getValidInput(&let, &num, Animals);
    if (animal == Octopus) getValidInput(&let, &num, Octopus);
    if (animal == Penguin) {
        getValidInput(&let, &num, Octopus);
        if (!board.isFaceUp(let, num)) board.turnFaceUp(let, num); else board.turnFaceDown(let, num);
    }
    return board.getCard(let, num);
}

void Game::getValidInput(Letter *letter, Number *number, const FaceAnimal &faceAnimal) {
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
            if (faceAnimal != Octopus && !board.isFaceUp(*letter, *number)) break;
            else if (mode == 2 && faceAnimal == Octopus && isValidCard(*letter, *number)) break;
            else cout << "Card is already faced up!" << endl;
        } catch (const exception &exc) {
            cout << "Invalid Card Selected, please try again" << endl;
            cerr << exc.what() << endl;
        }
    }
}

bool Game::isValidCard(const Letter &letter, const Number &number) {
    int let = static_cast<Letter>(letter) - 1;
    int num = static_cast<Number>(number) - 1;
    if (let >= 0 && let <= 4 && num >= 0 && num <= 4) {
        if (letter == 2 && number == 2) { throw out_of_range("Not allowed to pick treasure card! game"); }
        else { return true; }
    } else {
        cout << let << num << endl;
        throw out_of_range("Card is out of range");
    }
}

void Game::awardActivePlayers() {
    for (auto &p: players) if (p.isActive() && !rewardDeck.empty()) p.addReward(*rewardDeck.back()), rewardDeck.pop_back();
}

ostream &operator<<(ostream &os, const Game &game) {
    if (game.mode == 1 && game.getRound() < 7) {
        os << game.board << endl;
        for (const auto &player: game.players) { os << player << endl; }
    } else if (game.mode == 2) { game.expertModePrint(); }
    else game.printLeastToMostRubiesAndWinner();
    return os;
}

void Game::swapCards(const Letter &l1, const Number &n1, const Letter &l2, const Number &n2) {
    board.turnFaceDown(l2, n2);
    cout << l1 << n1 << " : " << l2 << n2 << endl;
    board.setCard(l1, n1, nullptr);
    board.setCard(l2, n2, nullptr);
}

void Game::printLeastToMostRubiesAndWinner() const {
    vector<Player> playerS = players;
    for (auto &player: playerS) player.setDisplayMode(true);
    int winCounter = 1;
    sort(playerS.begin(), playerS.end());
    for (auto &player : playerS) {
        if (winCounter++ == playerS.size()) { cout << "Winner : "; }
        cout << player.getName() << " with Rubies: " << player.getNRubies() << endl;
        player.setDisplayMode(false);
    }
}

void Game::expertModePrint() const {
    for (int i = 0; i < 3; i++) {
        for (auto const&[key, val] : cardMap) { cout << (*val)(i) << " "; };
        cout << endl;
    }
    for (auto const &card : cardMap) { cout << card.first << "  "; };
    cout << endl;
}

int Game::toEnum(const char &input) {
    switch (input) {
        case 'A':
        case '1':
            return 1;
        case 'B':
        case '2':
            return 2;
        case 'C':
        case '3':
            return 3;
        case 'D':
        case '4':
            return 4;
        case 'E':
        case '5':
            return 5;
        default:
            return -1;
    }
}

Card *Game::getExpertCard(const Letter &letter, const Number &number) {
    Letter let = letter;
    Number num = number;
    board.turnFaceUp(let, num);
    return board.getCard(let, num);
}

void Game::setExpertCurrentCard(const Card *card) {
    if (card != nullptr) {
        vector<const Card *> &cardVector = cards[static_cast<int>(currentSide)];
        cardVector.push_back(card);
    } else if (card == nullptr && !cards[static_cast<int>(currentSide)].empty() &&
               twoCardsSelected()) { clearSelectedCards(); }
}

void Game::getExpertRulesInput() {
    Letter letter = Z;
    Number number = Zero;
    while (true) {
        getExpertCard(letter, number, Walrus);
        if (convertToString(letter, number) == walrusBlockValue) cout << "Selected Card blocked by walrus" << endl;
        else break;
    }
    Card *selectedCard = getExpertCard(letter, number);
    setCard(letter, number, selectedCard);
    setExpertCurrentCard(selectedCard);
    expertRules(selectedCard, letter, number, sideCounter);
}

void Game::expertRules(Card *card, Letter &letter, Number &number, int &sideCounter) {
    switch (card->getAnimal()) {
        case 'O':
            expertOctopus(card, letter, number);
            break;
        case 'P':
            expertPenguin(sideCounter);
            break;
        case 'C':
            expertCrab(card, letter, number, sideCounter);
            break;
        case 'W':
            expertWalrus();
            break;
        default:
            expertTurtle();
            break;
    }
}

void Game::expertOctopus(Card *card, Letter &letter, Number &number) {
    cout << "You have picked an Octopus!" << endl;
    string pick = "Pick position with an adjacent card in the same (row or column) to swap: ";
    cout << pick << endl;
    Letter _letter = Z;
    Number _number = Zero;
    while (true) {
        getExpertCard(_letter, _number, Octopus);
        if (!(_letter == letter || number == _number)) cout << "Invalid Card! " + pick << endl; else break;
    }
    char cara = LetterToChar(_letter);     //card to be swapped with second card
    char cara2 = LetterToChar(letter);     //current card
    Card *selectedCard = getExpertCard(_letter, _number); //turns face up
    map<string, Card *> &cardMap = getCardMap();
    if (cardMap.count(cara + to_string(_number))) {     //if the second card is already face up
        cout << cara + to_string(_number) << endl;
        Card *temp = card;
        card = selectedCard;
        selectedCard = temp;
        cardMap.operator[](cara + to_string(_number)) = selectedCard; //swap hashes
        cardMap.operator[](cara2 + to_string(number)) = card;
    } else {    //swapping with faced down card
        board.turnFaceDown(_letter, _number);  //hideCard(_letter, _number); //turn face down
        auto it = (cardMap).find(cara2 + to_string(number));
        cardMap.erase(it);
        Card *temp = card;
        card = selectedCard;
        selectedCard = temp;
        cardMap.operator[](cara + to_string(_number)) = selectedCard;         //hashed to new location
        swapCards(letter, number, _letter, _number); //Expert Octopus //_ underscore is face down// normal is face up
    }
}

void Game::expertPenguin(int &sideCounter) {
    cout << "You have picked a Penguin!" << endl;
    cout << "Pick a card to change face up or face down: " << endl;
    Letter someLetter = Z;
    Number someNumber = Zero;
    Card *selectedCard = getExpertCard(someLetter, someNumber, Penguin);
    char cara = LetterToChar(someLetter);
    if (cardMap.count(cara + to_string(someNumber))) {
        cout << "Turning Face down :" << endl;
        cardMap.erase(cara + to_string(someNumber));
        board.turnFaceDown(someLetter, someNumber);//game.hideCard(someLetter, someNumber);
    } else {
        cout << "Turning Face Up:" << endl;
        cardMap.operator[](cara + to_string(someNumber)) = selectedCard;
        board.turnFaceUp(someLetter, someNumber);
        //setExpertCurrentCard(selectedCard);
    }
    cout << *selectedCard << endl;
}

void Game::expertWalrus() {
    cout << "You have picked a Walrus!" << endl;
    cout << "Pick a card to block from being chosen in the next round:" << endl;
    Letter someLetter = Z;
    Number someNumber = Zero;
    getExpertCard(someLetter, someNumber, Walrus);
    walrusBlockValue = LetterToChar(someLetter) + to_string(someNumber);
}

void Game::expertCrab(Card *card, Letter &letter, Number &number, int &sideCounter) {
    Player &player = getPlayer(sides[sideCounter]);
    cout << "You have picked a Crab!" << endl;
    cout << *card << endl;
    cout << "Pick another card. If it doesn't match, you lose the round:" << endl;
    Letter _letter = Z;
    Number _number = Zero;
    Card *selectedCard;
    while (true) {
        cout << *(selectedCard = getExpertCard(_letter, _number, Crab)) << endl;
        if (selectedCard->getColor() == card->getColor() && selectedCard->getAnimal() == card->getAnimal()) {
            cout << "This is the card you just picked. Choose another" << endl;
        } else break;
    }
    cout << player.getName() + " picked:" << endl;
    if (selectedCard->getColor() != card->getColor() && selectedCard->getAnimal() != card->getAnimal()) {
        cout << "The cards didn't match :( " + player.getName() + " is out of the current round." << endl;
        player.setActive(false);
    } else {
        cout << "The cards matched :) " + player.getName() + " is still in the current round." << endl;
        char cara = LetterToChar(_letter);
        cardMap.operator[](cara + to_string(_number)) = selectedCard;
        board.turnFaceUp(_letter, _number);
    }
}

void Game::expertTurtle() {
    cout << "You have picked a Turtle!" << endl;
    cout << "Skipping next player's turn." << endl;
    sideCounter = static_cast<int>((sideCounter + 1) % players.size());
}

map<string, Card *> &Game::getCardMap() { return cardMap; }


#ifdef TEST_GAME

int main() {
    cout << "TEST_GAME" << endl;
    int sideCounter, nPlayers;
    cout << "Testing Game Constructor" << endl;
    Game game(sideCounter, nPlayers);
    assert(sideCounter == nPlayers - 1);
    cout << "Testing Game Players" << endl;
    assert(nPlayers >= 2 && nPlayers <= 4);
    Player *currentPlayer = &game.getPlayer(sides[(sideCounter = (sideCounter + 1) % nPlayers)]);
    assert(currentPlayer != nullptr);
    cout << "Testing Game methods" << endl;
    assert(game.getRound() == 1);
    cout << "Picking first card" << endl;
    Card *cardPtr = game.getCard(Z, Zero);
    assert(cardPtr != nullptr);
    game.setCurrentCard(cardPtr);
    cout << "Picking second card" << endl;
    Card *cardPtr2 = game.getCard(Z, Zero);
    assert(cardPtr2 != nullptr);
    game.setCurrentCard(cardPtr2);
    assert(game.getPreviousCard() != nullptr);
    assert(game.getCurrentCard() != nullptr);
    game.nextRound();
    assert(game.getRound() == 2);
    cout << "Testing Print Game" << endl;
    cout << game << endl;
    cout << "Testing Completed" << endl;
}

#endif