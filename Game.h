//
// Created by martin on 9/21/23.
//

#ifndef DURAK_GAME_H
#define DURAK_GAME_H

#include <vector>

#include "Player.h"
#include "Deck.h"

class Game {
public:
    explicit Game(int numberOfPlayers);
    ~Game();
    void endGame();
    std::vector<Player*> getPlayers();
private:
    std::vector<Player*> players;
    Deck* deck;
};


#endif //DURAK_GAME_H
