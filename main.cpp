#include <iostream>

#include "Deck.h"
#include "Game.h"

void test(){
    Game game(2);

    game.getPlayers().at(0)->showHand();
    game.getPlayers().at(1)->showHand();
}

int main() {
    test();
    return 0;
}


