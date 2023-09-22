#include "Deck.h"
#include "Card.h"

#include <algorithm>
#include <random>

Deck::Deck() {
    for (Suit::Suit suit : Suit::Suits) {
        for (Rank::Rank rank : Rank::Ranks) {
            Card card(suit, rank);
            this->cards.push_back(card);
        }
    }
    shuffle();
}

void Deck::shuffle() {
    auto rd = std::random_device {};
    auto rng = std::default_random_engine { rd() };

    std::shuffle(std::begin(this->cards), std::end(this->cards), rng);
}

void Deck::dealCards(std::vector<Player>& players) {
    size_t numberOfPlayerToDealCardTo = 0;
    size_t numberOfAllPlayers = players.size();

    while(cards.empty()){
        Card cardToDeal = cards.back();
        cards.pop_back();

        players.at(numberOfPlayerToDealCardTo).addToHand(cardToDeal);
        numberOfPlayerToDealCardTo = (numberOfPlayerToDealCardTo + 1) % numberOfAllPlayers;

    }
}


