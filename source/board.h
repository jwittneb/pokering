#ifndef __BOARD_H__
#define __BOARD_H__
#include "card.h"
#include "deck.h"
#include "enums.h"
#include <string>
#include <map>

//TODO
//For now, the board will be all 5 cards at once, once this is ready
//to go, make it so that it works with flop, turn, river

class Board {
  int numBoardCards;
  Card *boardCards[5];
  int suitity[NUM_CARD_SUITS];

  public:
    Board(Card *first, Card *second, Card *third, Card *fourth, Card *fifth);
    //Board(Deck *theDeck, Card first, Card second, Card third, Card fourth, Card fifth);
    Board(Deck *theDeck);
    
    int get_num_boardCards();

    int straight_height(Card *hand1, Card* hand2, int suit);
    int flush_suit(Card *hand1, Card *hand2);

    void print_board();
    std::string fullboard_core_value(Card *hand1, Card *hand2);

    ~Board();
};

#endif
