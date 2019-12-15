#ifndef __RANGE_ENTRY_H__
#define __RANGE_ENTRY_H__
#include <string>
#include "hand.h"

class RangeEntry {
  Hand *entry;

  std::string action;
  public:
    Card *get_card1();
    Card *get_card2();

    RangeEntry();
    RangeEntry(Hand *input);
    RangeEntry(Card card1, Card card2);
    ~RangeEntry();
};

#endif
