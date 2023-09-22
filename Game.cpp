

#include "Game.h"
#include "Deck.h"

void Game::startGame(int numberOfPlayers) {
    for (int i = 0; i < numberOfPlayers; ++i) {
        auto player = new Player();
        this->players.push_back(player);
    }

    this->deck = new Deck();
    deck->dealCards(players);
}

void Game::endGame() {
    delete deck;

    while (!players.empty()) {
        delete players.back();
        players.pop_back();
    }
}

std::vector<Player*> Game::getPlayers() {
    return this->players;
}

