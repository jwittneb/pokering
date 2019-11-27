#ifndef __EVALUATOR_H__
#define __EVALUATOR_H__
#include "board.h"
#include "card.h"
#include "enums.h"
#include "handvalue.h"

class Evaluator {  
    void pairity_hand(Board &theBoard, const Card *hand1, const Card *hand2, HandValue &val);
    void straight_hand(Board &theBoard, const Card *hand1, const Card *hand2, HandValue &val, int suit);
    void flush_hand(Board &theBoard,const Card *hand1, const Card *hand2, HandValue &val);
    void reset_suitity();
    void get_suitity(Board &theBoard, const Card *hand1, const Card *hand2);

    int suitity[NUM_CARD_SUITS];

  public:
    void find_handvalue(Board &theBoard, const Card *hand1, const Card *hand2, HandValue &val);
    //HandValue hand_value(Board, &theBoard, const Card &hand1, const Card &hand2, Hand);

    Evaluator();
    ~Evaluator();
};

#endif
