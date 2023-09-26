#ifndef DURAK_CARD_H
#define DURAK_CARD_H

#include <cstdint>
#include <iostream>
#include <string>

namespace Suit{
    enum Suit { ACORNS, LEAVES, HEARTS, BALLS };
    static const Suit Suits[] = {Suit::HEARTS, Suit::LEAVES, Suit::ACORNS, Suit::BALLS};
    static std::string toString(Suit suit) {
        switch (suit) {
            case Suit::ACORNS: return "Zalud";
            case Suit::HEARTS: return "Cerven";
            case Suit::BALLS: return "Gula";
            case Suit::LEAVES: return "Zelen";
            default: return "";
        }
    }
}
namespace Rank{
    enum Rank { SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
    static const Rank Ranks[] = {Rank::SEVEN, Rank::EIGHT, Rank::NINE, Rank::TEN, Rank::JACK,
                                 Rank::QUEEN, Rank::KING, Rank::ACE};
    static std::string toString(Rank rank) {
        switch (rank) {
            case Rank::SEVEN: return "7";
            case Rank::EIGHT: return "8";
            case Rank::NINE: return "9";
            case Rank::TEN: return "10";
            case Rank::JACK: return "J";
            case Rank::QUEEN: return "Q";
            case Rank::KING: return "K";
            case Rank::ACE: return "A";
            default: return "";
        }
    }
}

class Card {
private:
    Suit::Suit suit;
    Rank::Rank rank;
public:
    Card(Suit::Suit suit, Rank::Rank rank);

    [[nodiscard]] Suit::Suit getSuit() const;
    [[nodiscard]] Rank::Rank getRank() const;
    [[nodiscard]] int8_t getValue() const;
    void printCard() const;

    friend bool operator==(const Card& card1, const Card& card2);
};

#endif //DURAK_CARD_H
