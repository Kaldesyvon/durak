#include "Player.h"
#include <algorithm>

Player::Player(std::string name) {
    this->name = name;
    this->cardOnHand = std::vector<Card>{};
}

void Player::addToHand(Card card) {
    this->cardOnHand.push_back(card);
}

std::string Player::getName() {
    return name;
}

Card Player::playCard(Card cardToPlay) {
    // checks if player can play it
    auto position = std::find(this->cardOnHand.begin(), this->cardOnHand.end(), cardToPlay);
    if (position != this->cardOnHand.end())
        this->cardOnHand.erase(position);

    return cardToPlay;

}