#ifndef __BOARD_H__
#define __BOARD_H__
#include "card.h"
#include "deck.h"

//For now, the board will be all 5 cards at once, once this is ready
//to go, make it so that it works with flop, turn, river

class Board {
  Card *boardCards[5];

  public:
    Board(Card *first, Card *second, Card *third, Card *fourth, Card *fifth);
    //Board(Deck *theDeck, Card first, Card second, Card third, Card fourth, Card fifth);
    Board(Deck *theDeck);

    void print_board();

    ~Board();
};

#endif
