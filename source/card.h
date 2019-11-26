#ifndef __CARD_H__
#define __CARD_H__
#include "enums.h"

class Card {
    cardSuit suit;
    cardValue value;
  public:
    cardSuit get_suit() const { return suit; }
    cardValue get_value() const { return value; }

    void print();

    Card(cardValue value, cardSuit suit);
    Card(int value, int suit);
    ~Card();
};

#endif
