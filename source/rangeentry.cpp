#include "rangeentry.h"
#include "card.h"

RangeEntry::RangeEntry(Card icard1, Card icard2) {
  card1 = new Card(icard1.get_value(), icard1.get_suit());
  card2 = new Card(icard2.get_value(), icard2.get_suit());
}
    
//RangeEntry::RangeEntry(Card *icard1, Card *icard2, bool iinRange) {
//  card1 = icard1;
//  card2 = icard2;
//  inRange = iinRange;
//}

//void RangeEntry::add_to_range() {
//  inRange = true;
//}

Card *RangeEntry::get_card1() {
  return card1;
}

Card *RangeEntry::get_card2() {
  return card2;
}

RangeEntry::~RangeEntry() {
}
