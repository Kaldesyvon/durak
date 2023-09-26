#include <iostream>
#include <algorithm>

#include "Player.h"

Player::Player() {
    std::cout << "enter name: ";
    std::cin >> this->name;
    this->cardsOnHand = std::vector<Card*>{};
    this->tromf = {};
}

Player::~Player(){
    while(!cardsOnHand.empty()){
        delete cardsOnHand.back();
        cardsOnHand.pop_back();
    }
}

void Player::addToHand(Card* card) {
    this->cardsOnHand.push_back(card);
}

std::string Player::getName() {
    return name;
}

void Player::setTromf(Suit::Suit suit) {
    this->tromf = this->tromf ? this->tromf: suit;
    std::cout << this->name << " has tromf " << Suit::toString(suit) << std::endl;
}

bool Player::isValidPositionOfCard(int index) {
    if (index < 0 || index > this->cardsOnHand.size()) {
        std::cout << "Invalid index!";
        return false;
    }
    return true;
}

Card* Player::playCard(Card* previousCard) {
    int indexOfCardToPlay = -1;
    Card* playedCard = nullptr;

    do{
        std::cout << "Choose card to play: ";
        this->showHand();
        std::cin >> indexOfCardToPlay;
        playedCard = this->cardsOnHand.at(indexOfCardToPlay); // TODO: nekontroluje valid position vcas
    } while (!isValidPositionOfCard(indexOfCardToPlay) && isPlayedCardValid(previousCard, playedCard));

    // asi daco plano robi
    std::remove(this->cardsOnHand.begin(), this->cardsOnHand.end(), playedCard); // NOLINT(*-unused-return-value)

    return playedCard;
}

std::vector<Card*> Player::getCardsOnHand(){
    return this->cardsOnHand;
}

void Player::showHand() {
//    std::cout << this->name << " has these cards: ";
    for (auto i = 0; i < this->cardsOnHand.size(); i++) { // TODO: beautify pls
        std::cout << i << "-";
        this->cardsOnHand.at(i)->printCard();
    }

    std::cout << std::endl;
}

bool Player::isPlayedCardValid(Card *previousCard, Card *playedCard) { // TODO: include TROMFs pls
    if (previousCard->getValue() < playedCard->getValue()) {
        return true;
    }
    return false;
}

Card *Player::playCard() { // TODO: make this function  pls
    int indexOfCardToPlay = -1;
    Card* playedCard = nullptr;

    do{
        std::cout << "Choose card to play: ";
        this->showHand();
        std::cin >> indexOfCardToPlay;
        playedCard = this->cardsOnHand.at(indexOfCardToPlay);
    } while (!isValidPositionOfCard(indexOfCardToPlay));

    std::remove(this->cardsOnHand.begin(), this->cardsOnHand.end(), playedCard); // NOLINT(*-unused-return-value)

    return playedCard;
}
