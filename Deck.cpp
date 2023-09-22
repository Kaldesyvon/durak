#include "Deck.h"
#include "Card.h"

#include <algorithm>
#include <random>

Deck::Deck() {
    for (Suit::Suit suit : Suit::Suits) {
        for (Rank::Rank rank : Rank::Ranks) {
            Card* card = new Card(suit, rank);
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

void Deck::deleteDeck() {
    while(!cards.empty()){
        delete cards.back();
        cards.pop_back();
    }
}

void Deck::dealCards(std::vector<Player*>& players) {
    size_t numberOfPlayerToDealCardTo = 0;
    size_t numberOfAllPlayers = players.size();

    while(!this->cards.empty()){
        Card* cardToDeal = cards.back();
        cards.pop_back();

        players.at(numberOfPlayerToDealCardTo)->addToHand(cardToDeal);
        ++numberOfPlayerToDealCardTo %= numberOfAllPlayers;
    }
}


