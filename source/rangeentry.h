#ifndef __RANGE_ENTRY_H__
#define __RANGE_ENTRY_H__
#include "card.h"


class RangeEntry {
  Card *card1;
  Card *card2;

  bool inRange;

  public:
    bool is_in_range();
    Card *get_entry_cards();

    RangeEntry(Card *card1, Card *card2);
    RangeEntry(Card *card1, Card *card2, bool inRange);
    ~RangeEntry();

};

#endif
