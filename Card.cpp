#include "Card.h"

Card::Card(Suit::Suit suit, Rank::Rank rank) {
    this->suit = suit;
    this->rank = rank;
}

Suit::Suit Card::getSuit() const {
    return suit;
}

Rank::Rank Card::getRank() const {
    return rank;
}

int8_t Card::getValue() const {
    switch (rank) {
        case Rank::SEVEN: return 0;
        case Rank::EIGHT: return 1;
        case Rank::NINE: return 2;
        case Rank::TEN: return 3;
        case Rank::JACK: return 4;
        case Rank::QUEEN: return 5;
        case Rank::KING: return 6;
        case Rank::ACE: return 7;
        default: return -1;
    }
}

void Card::printCard() const {
    std::cout << "[" << toString(this->getSuit()) << ":" << toString(this->getRank()) << "] ";
}

