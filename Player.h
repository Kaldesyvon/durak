#ifndef DURAK_PLAYER_H
#define DURAK_PLAYER_H

#include <string>
#include <vector>
#include "Card.h"

class Player{
private:
    std::string name;
    std::vector<Card> cardOnHand;
public:
    Player(std::string name);
    std::string getName();
    void addToHand(Card card);
    Card playCard(Card card);
//    bool isLastStanding();
};

#endif //DURAK_PLAYER_H
