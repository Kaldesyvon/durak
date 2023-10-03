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

std::vector<Card*> Player::getCardsOnHand(){
    return this->cardsOnHand;
}

void Player::showHand() {
    for (auto i = 0; i < this->cardsOnHand.size(); i++) { // TODO: beautify pls
        std::cout << i << "-";
        this->cardsOnHand.at(i)->printCard();
    }

    std::cout << std::endl;
}

bool Player::isPlayedCardValid(Card *previousCard, Card *playedCard) { // TODO: include TROMFs pls
    if (previousCard == nullptr) return true;

    if (previousCard->getValue() < playedCard->getValue()) return true;

    return false;
}

Card* Player::playCard(Card* previousCard) {
    int indexOfCardToPlay = -1;
    Card* playedCard = nullptr;
    bool validPosition;
    bool validPlayedCard;

    do{
        std::cout << "Choose card to play:\n";
        this->showHand();
        std::cin >> indexOfCardToPlay;

        validPosition = isValidPositionOfCard(indexOfCardToPlay);
        playedCard = this->cardsOnHand.at(indexOfCardToPlay);

        validPlayedCard = isPlayedCardValid(previousCard, playedCard);
    } while (!validPosition || !validPlayedCard);

    this->cardsOnHand.erase(std::remove_if(this->cardsOnHand.begin(), this->cardsOnHand.end(), [playedCard](Card *card) {
        return playedCard == card;
    }), this->cardsOnHand.end());

    return playedCard;
}

Suit::Suit Player::getTromf() {
    return this->tromf;
}
