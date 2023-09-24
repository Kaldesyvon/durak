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

Card* Player::playCard(Card* cardToPlay) {
    // checks if player can play it
    auto position = std::find(this->cardsOnHand.begin(), this->cardsOnHand.end(), cardToPlay);
    if (position != this->cardsOnHand.end())
        this->cardsOnHand.erase(position);

    return cardToPlay;

}

std::vector<Card*> Player::getCardsOnHand(){
    return this->cardsOnHand;
}

void Player::showHand() {
    std::cout << this->name << " has these cards: ";
    for (auto card : cardsOnHand) {
        std::cout << Suit::toString(card->getSuit()) << ":";
        std::cout << Rank::toString(card->getRank()) << ", ";
    }
    std::cout << std::endl << std::endl;
}