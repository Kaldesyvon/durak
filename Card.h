#ifndef DURAK_CARD_H
#define DURAK_CARD_H

#include <cstdint>

enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
enum Rank { SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

class Card {
private:
    Suit suit;
    Rank rank;
public:
    Card(Suit suit, Rank rank);

    Suit getSuit() const;
    Rank getRank() const;
    __int8_t getValue() const;

    friend bool operator==(const Card& card1, const Card& card2);
};

#endif //DURAK_CARD_H
