#include <iostream>

#include "Deck.h"
#include "Game.h"

void test(){
    Game game;

    game.startGame(2);

    game.getPlayers().at(0).showHand();
}

int main() {
    test();
    return 0;
}


