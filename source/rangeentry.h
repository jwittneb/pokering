#ifndef __RANGE_ENTRY_H__
#define __RANGE_ENTRY_H__
#include "card.h"
#include <string>

class RangeEntry {
  Card *card1;
  Card *card2;

  std::string action;
  public:
    Card *get_card1();
    Card *get_card2();

    RangeEntry();
    RangeEntry(Card card1, Card card2);
    ~RangeEntry();
};

#endif
