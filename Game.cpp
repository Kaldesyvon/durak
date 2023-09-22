

#include "Game.h"
#include "Deck.h"

void Game::startGame(int numberOfPlayers) {
    Deck deck;
    for (int i = 0; i < numberOfPlayers; ++i) {
        Player player;
        this->players.push_back(player);
    }
}

std::vector<Player> Game::getPlayers() {
    return this->players;
}
