#ifndef __EVALUATOR_H__
#define __EVALUATOR_H__
#include "board.h"
#include "card.h"
#include "enums.h"

class Evaluator {  
    int max_pairity(Board &theBoard, const Card &hand1, const Card &hand2);
    int straight_height(Board &theBoard, const Card &hand1, const Card &hand2, int suit);
    int flush_suit(Board &theBoard,const Card &hand1, const Card &hand2);

    int suitity[NUM_CARD_SUITS];
  public:
    void reset_suitity();
    void get_suitity(Board &theBoard, const Card &hand1, const Card &hand2);
    std::string core_value(Board &theBoard, const Card &hand1, const Card &hand2);

    Evaluator();
    ~Evaluator();
};

#endif
