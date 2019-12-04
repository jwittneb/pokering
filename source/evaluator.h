#ifndef __EVALUATOR_H__
#define __EVALUATOR_H__
#include "board.h"
#include "card.h"
#include "enums.h"
#include "handvalue.h"
#include "rangeentry.h"

class Evaluator { 
    Board *iBoard; 
  public:
    bool operator()(RangeEntry entry1, RangeEntry entry2);

    Evaluator(Board *theBoard);
    ~Evaluator();
};

#endif
