//
// Created by martin on 9/21/23.
//

#ifndef DURAK_GAME_H
#define DURAK_GAME_H

#include <vector>

#include "Player.h"

class Game {
private:
    std::vector<Player> players;
public:
    void startGame(int numberOfPlayers);
    std::vector<Player> getPlayers();
};


#endif //DURAK_GAME_H
