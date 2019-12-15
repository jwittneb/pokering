#ifndef __HAND_H__
#define __HAND_H__
#include "card.h"
#include "handvalue.h"
#include "enums.h"
#include "board.h"
#include "deck.h"

//Note: a standard "Hand" class should have hole1 >= hole2.
//ie. hand1 = Jc, hand2 = 10s would be a valid Hand, whereas
//    hand1 = 10s, hand2 = Jc would not be a valid Hand.
//
//This could potentially cause many Hand methods to be more efficient, but it is currently
//implemented in a more robust manner to cover non-valid Hand formations.

class Hand {
  Card *hand1;
  Card *hand2;
  HandValue value;
  
  int suitity[NUM_CARD_SUITS];

  void pairity_hand(Board *theBoard, HandValue &val);
  void straight_hand(Board *theBoard, HandValue &val, int suit);
  void flush_hand(Board *theBoard, HandValue &val);
  void get_suitity(Board *theBoard);
  void reset_suitity();

  int pot_imp_1(Board *theBoard);

  public:  
    Card *get_card1();
    Card *get_card2();
    HandValue get_value();

    Hand(Card *Card1, Card *Card2);
    ~Hand();

    void find_handvalue(Board *theBoard);
};

#endif
