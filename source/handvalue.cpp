#include "handvalue.h"
#include <iostream>

void HandValue::set_core(Hand core) {
  coreValue = core;
}

void HandValue::set_tb(int tbindex, int tbval) {
  tiebreaks[tbindex] = tbval;
}

int HandValue::get_core() const {
  return coreValue;
}

int HandValue::get_tb(int index) const {
  return tiebreaks[index];
}

HandValue::HandValue(Hand core, int tb1, int tb2, int tb3, int tb4, int tb5) {
  coreValue = core;
  tiebreaks[0] = tb1;
  tiebreaks[1] = tb2;
  tiebreaks[2] = tb3;
  tiebreaks[3] = tb4;
  tiebreaks[4] = tb5;
}
    
HandValue::~HandValue() {}

bool HandValue::operator==(const HandValue &right) {
  if (coreValue == right.get_core()) {
    for (int i=0; i<5; ++i) {
      if (tiebreaks[i] != right.get_tb(i)) {
        return false;
      }
    }
    return true;
  }
  return false;
}

bool HandValue::operator<(const HandValue &right) {
  if (coreValue < right.get_core()) {
    return true;
  } 
  if (coreValue == right.get_core()) {
    if (tiebreaks[0] < right.get_tb(0)) {
      return true;
    }
    if (tiebreaks[0] == right.get_tb(0)) {
      if (tiebreaks[1] < right.get_tb(1)) {
        return true;
      }
      if (tiebreaks[1] == right.get_tb(1)) {
        if (tiebreaks[2] < right.get_tb(2)) {
          return true;
        }
        if (tiebreaks[2] == right.get_tb(2)) {
          if (tiebreaks[3] < right.get_tb(3)) {
            return true;
          }
          if (tiebreaks[3] == right.get_tb(3)) {
            return (tiebreaks[4] < right.get_tb(4));
          }
        }
      }
    }
  }
  return false;
}

