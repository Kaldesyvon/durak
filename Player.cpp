#include <iostream>
#include <algorithm>

#include "Player.h"

Player::Player() {
    std::cout << "enter name: ";
    std::cin >> this->name;
    this->cardsOnHand = std::vector<Card*>{};
//    this->tromf =;
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

//void Player::setTromf(Suit::Suit suit) {
//    this->tromf = this->tromf ? this->tromf: suit;
//}

Card* Player::playCard(Card* cardToPlay) {
    // checks if player can play it
    auto position = std::find(this->cardsOnHand.begin(), this->cardsOnHand.end(), cardToPlay);
    if (position != this->cardsOnHand.end())
        this->cardsOnHand.erase(position);

    return cardToPlay;

}

void Player::showHand() {
    std::cout << this->name << " has these cards: ";
    for (auto card : cardsOnHand) {
        switch (card->getSuit()) {
            case Suit::ACORNS: { std::cout << "Zalud:"; break; }
            case Suit::HEARTS: { std::cout << "Srdce:"; break; }
            case Suit::BALLS: { std::cout << "Gula:"; break; }
            case Suit::LEAVES: { std::cout << "Zelen:"; break; }
            default: break;
        }
        switch (card->getRank()) {
            case Rank::SEVEN: { std::cout << "7, "; break; }
            case Rank::EIGHT: { std::cout << "8, "; break; }
            case Rank::NINE: { std::cout << "9, "; break; }
            case Rank::TEN: { std::cout << "10, "; break; }
            case Rank::JACK: { std::cout << "J, "; break; }
            case Rank::QUEEN: { std::cout << "Q, "; break; }
            case Rank::KING: { std::cout << "K, "; break; }
            case Rank::ACE: { std::cout << "A, "; break; }
            default: break;
        }
    }
    std::cout << std::endl;
}