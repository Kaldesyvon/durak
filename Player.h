#ifndef DURAK_PLAYER_H
#define DURAK_PLAYER_H

#include <string>
#include <vector>
#include "Card.h"

class Player{
public:
    Player();
    ~Player();
//    void setTromf(Suit::Suit suit);
    std::string getName();
    void addToHand(Card* card);
    Card* playCard(Card* card);
    void showHand();
//    bool isLastStanding();
private:
    std::string name;
    std::vector<Card*> cardsOnHand;
//    Suit tromf;
};

#endif //DURAK_PLAYER_H
