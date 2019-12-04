#include "evaluator.h"
#include "hand.h"
#include <iostream>

bool Evaluator::operator()(RangeEntry entry1, RangeEntry entry2) {
  Hand h1 = Hand(entry1.get_card1(), entry1.get_card2());
  Hand h2 = Hand(entry2.get_card1(), entry2.get_card2());
  h1.find_handvalue(iBoard);
  h2.find_handvalue(iBoard);
  return (h1.get_value() < h2.get_value());
}

Evaluator::Evaluator(Board *theBoard) {
  iBoard = theBoard;
}

Evaluator::~Evaluator() {}
