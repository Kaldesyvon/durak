#ifndef DURAK_CARD_H
#define DURAK_CARD_H

#include <cstdint>

namespace Suit{
    enum Suit { ACORNS, LEAVES, HEARTS, BALLS };
    static const Suit Suits[] = {Suit::ACORNS, Suit::LEAVES, Suit::HEARTS, Suit::BALLS};
}
namespace Rank{
    enum Rank { SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
    static const Rank Ranks[] = {Rank::SEVEN, Rank::EIGHT, Rank::NINE, Rank::TEN, Rank::JACK, Rank::QUEEN, Rank::KING, Rank::ACE};
}

class Card {
private:
    Suit::Suit suit;
    Rank::Rank rank;
public:
    Card(Suit::Suit suit, Rank::Rank rank);

    Suit::Suit getSuit() const;
    Rank::Rank getRank() const;
    int8_t getValue() const;

    friend bool operator==(const Card& card1, const Card& card2);
};

#endif //DURAK_CARD_H
