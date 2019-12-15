#ifndef __CARD_H__
#define __CARD_H__
#include "enums.h"
#include <string>

class Card {
    cardSuit suit;
    cardValue value;
  public:
    cardSuit get_suit() const { return suit; }
    cardValue get_value() const { return value; }

    std::string string_print();
    void print();

    Card(cardValue value, cardSuit suit);
    Card(int value, int suit);
    Card();
    ~Card();
};

#endif
