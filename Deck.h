#ifndef DURAK_DECK_H
#define DURAK_DECK_H

#include <vector>

#include "Card.h"
#include "Player.h"


class Deck{
public:
    Deck();
private:
    std::vector<Card> cards;
    void shuffle();
    void dealCards(std::vector<Player>& players);
};

#endif //DURAK_DECK_H
