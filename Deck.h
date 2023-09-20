#ifndef DURAK_DECK_H
#define DURAK_DECK_H

#include <vector>

#include "Card.h"


class Deck{
public:
    static Deck& getInstance();

private:
    Deck();
    std::vector<Card> cards{};
    void shuffle();
    Card dealCard();
};

#endif //DURAK_DECK_H
