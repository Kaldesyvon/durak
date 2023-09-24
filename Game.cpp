#include <iostream>
#include <algorithm>

#include "Game.h"
#include "Deck.h"


Game::Game(int numberOfPlayers) {
    if (numberOfPlayers < 2 || numberOfPlayers > 4){
        std::cout << "Number of players must be at least 2 and maximum of 4!" << std::endl;
        return;
    }

    for (int i = 0; i < numberOfPlayers; ++i) {
        auto player = new Player();
        this->players.push_back(player);
    }

    this->deck = new Deck();
    deck->dealCards(players);
}

Game::~Game(){
    delete deck;

    while (!players.empty()) {
        delete players.back();
        players.pop_back();
    }
}

std::vector<Player*> Game::getPlayers() {
    return this->players;
}



void Game::gameLoop(){
    setTromfToPlayers();

//    while(players.size() != 1) {
//        break;
//    }
//    std::cout << players.at(0)->getName() << " is Durak!" << std::endl;
}

bool isHeartAceInPlayerHand(Player* player){
    auto playersCardsOnHand = player->getCardsOnHand();
    if (std::any_of(playersCardsOnHand.begin(), playersCardsOnHand.end(), [&](Card *card) {
        return
            card->getSuit() == Suit::HEARTS &&
            card->getRank() == Rank::ACE;
        })) {
        std::cout << player->getName() << " has a heart ace!" << std::endl;
        return true;
    }
    return false;
}

void Game::setTromfToPlayers(){
    int indexOfPlayerWithHeartAce;

    for (auto player : this->players) {
        if(isHeartAceInPlayerHand(player)){
            indexOfPlayerWithHeartAce = (int)(std::find(players.begin(), players.end(), player) - players.begin());
            break;
        }
    }

    const int numberOfPlayers = (int)players.size();

    for (int i = 0; i < numberOfPlayers; ++i) {
        players.at((indexOfPlayerWithHeartAce + i) % numberOfPlayers )->setTromf(Suit::Suits[i]);
    }
}

