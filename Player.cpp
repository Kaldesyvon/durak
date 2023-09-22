#include <iostream>
#include <algorithm>

#include "Player.h"

Player::Player() {
    std::cout << "enter name: ";
    std::cin >> this->name;
    this->cardsOnHand = std::vector<Card>{};
//    this->tromf =;
}

void Player::addToHand(Card& card) {
    this->cardsOnHand.push_back(card);
}

std::string Player::getName() {
    return name;
}

//void Player::setTromf(Suit::Suit suit) {
//    this->tromf = this->tromf ? this->tromf: suit;
//}

Card Player::playCard(Card cardToPlay) {
    // checks if player can play it
    auto position = std::find(this->cardsOnHand.begin(), this->cardsOnHand.end(), cardToPlay);
    if (position != this->cardsOnHand.end())
        this->cardsOnHand.erase(position);

    return cardToPlay;

}

void Player::showHand() {
    for (Card card : cardsOnHand) {
        switch (card.getSuit()) {
            case Suit::ACORNS: std::cout << "Zalud ";
            case Suit::HEARTS: std::cout << "Srdce ";
            case Suit::BALLS: std::cout << "Gula ";
            case Suit::LEAVES: std::cout << "Zelen ";
        }
        switch (card.getRank()) {
            case Rank::SEVEN: std::cout << "7,";
            case Rank::EIGHT: std::cout << "8,";
            case Rank::NINE: std::cout << "9,";
            case Rank::TEN: std::cout << "10,";
            case Rank::JACK: std::cout << "J,";
            case Rank::QUEEN: std::cout << "Q,";
            case Rank::KING: std::cout << "K,";
            case Rank::ACE: std::cout << "A,";
        }
    }
    std::cout << std::endl;
}