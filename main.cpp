#include <iostream>
#include "Card.h"

int main() {
    Card card1(HEARTS, ACE);
    Card card2(HEARTS, );
    std::cout << (card1 == card2);
    return 0;
}
