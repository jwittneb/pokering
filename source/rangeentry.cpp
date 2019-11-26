#include "rangeentry.h"
#include "card.h"

RangeEntry::RangeEntry(Card *icard1, Card *icard2) {
  card1 = icard1;
  card2 = icard2;
  inRange = false;
}
    
RangeEntry::RangeEntry(Card *icard1, Card *icard2, bool iinRange) {
  card1 = icard1;
  card2 = icard2;
  inRange = iinRange;
}

RangeEntry::~RangeEntry() {}
