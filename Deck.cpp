#include "Deck.h"
#include "Card.h"

#include <algorithm>
#include <random>

Deck::Deck() {
    for (Suit::Suit const suit : Suit::Suits) {
        for (Rank::Rank const rank : Rank::Ranks) {
            Card* card = new Card(suit, rank);
            this->cards.push_back(card);
        }
    }
    shuffle();
}

Deck::~Deck() {
    while(!cards.empty()){
        delete cards.back();
        cards.pop_back();
    }
}

void Deck::shuffle() {
    auto randomDevice = std::random_device {};
    auto randomEngine = std::default_random_engine { randomDevice() };

    std::shuffle(std::begin(this->cards), std::end(this->cards), randomEngine);
}

void Deck::dealCards(std::vector<Player*>& players) {
    size_t numberOfPlayerToDealCardTo = 0;
    const size_t numberOfAllPlayers = players.size();

    while(!this->cards.empty()){
        Card* cardToDeal = cards.back();
        cards.pop_back();

        players.at(numberOfPlayerToDealCardTo)->addToHand(cardToDeal);
        ++numberOfPlayerToDealCardTo %= numberOfAllPlayers;
    }
}



