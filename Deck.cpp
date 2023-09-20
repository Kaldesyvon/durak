#include "Deck.h"



Deck &Deck::getInstance() {
    static Deck instance;
    return instance;
}