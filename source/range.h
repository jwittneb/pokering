#ifndef __RANGE_H__
#define __RANGE_H__
#include "rangeentry.h"
#include <vector>
#include "evaluator.h"
#include "constants.h"

class Range {

  std::vector<RangeEntry> holdingsInRange;
  int rangeSize;

  public:
    void cold_bet_range(Evaluator &theEvaluator);
    void sort_range(Evaluator &theEvaluator);

    RangeEntry get_holding_in_range(int i);
    int get_rangesize();
    void remove_from_range(Card &toRemove);
   // void remove_from_range(Card &toRemove1, Card &toRemove2);

    Range();
    Range(std::vector<RangeEntry> holdings);
    ~Range();

};

#endif
