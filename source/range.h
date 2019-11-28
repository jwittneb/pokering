#ifndef __RANGE_H__
#define __RANGE_H__
#include "rangeentry.h"
#include <vector>
#include "evaluator.h"

class Range {

  std::vector<RangeEntry> holdingsInRange;
  int rangeSize;

  public:
    RangeEntry get_holding_in_range(int i);

    void sort_range(Evaluator &theEvaluator);
    int get_rangesize();

    void remove_from_range(Card &toRemove);
   // void remove_from_range(Card &toRemove1, Card &toRemove2);

    Range();
    Range(std::vector<RangeEntry> holdings);
    ~Range();

};

#endif
