#include "Card.h"

Card::Card(Suit suit, Rank rank) {
    this->suit = suit;
    this->rank = rank;
}

Suit Card::getSuit() const {
    return suit;
}

Rank Card::getRank() const {
    return rank;
}

__int8_t Card::getValue() const {
    switch (rank) {
        case SEVEN: return 0;
        case EIGHT: return 1;
        case NINE: return 2;
        case TEN: return 3;
        case JACK: return 4;
        case QUEEN: return 5;
        case KING: return 6;
        case ACE: return 7;
    }
}

bool operator==(const Card& card1, const Card& card2)  {
    return card1.getRank() == card2.getRank() && card1.getSuit() == card2.getSuit();
}
