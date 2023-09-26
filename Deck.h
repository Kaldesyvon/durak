#ifndef DURAK_DECK_H
#define DURAK_DECK_H

#include <vector>

#include "Card.h"
#include "Player.h"


class Deck{
public:
    Deck();
    ~Deck();
    void dealCards(std::vector<Player*>& players);
    void addPlayedCard(Card* card);
    std::vector<Card*> getCards();
private:
    void showDeck();
    std::vector<Card*> cards;
    void shuffle();
};

#endif //DURAK_DECK_H
