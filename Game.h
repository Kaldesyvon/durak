//
// Created by martin on 9/21/23.
//

#ifndef DURAK_GAME_H
#define DURAK_GAME_H

#include <vector>

#include "Player.h"
#include "Deck.h"

class Game {
private:
    std::vector<Player*> players;
    Deck* deck;
public:
    void startGame(int numberOfPlayers);
    void endGame();
    std::vector<Player*> getPlayers();
};


#endif //DURAK_GAME_H
