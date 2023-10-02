#ifndef DURAK_GAME_H
#define DURAK_GAME_H

#include <vector>

#include "Player.h"
#include "Deck.h"

class Game {
public:
    explicit Game(int numberOfPlayers);
    ~Game();
    void gameLoop();
    std::vector<Player*> getPlayers();
private:
    int numberOfPlayers;
    int setTromfToPlayersGetIndexOfFirstPlayer();
    std::vector<Player*> players;
    Deck* deck;
};


#endif //DURAK_GAME_H
