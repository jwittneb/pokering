#include "handvalue.h"

void HandValue::set_core(Hand core) {
  coreValue = core;
}

void HandValue::set_tb(int tbindex, int tbval) {
  tiebreaks[tbindex] = tbval;
}

int HandValue::get_core() const {
  return coreValue;
}

int HandValue::get_tb1() {
  return tiebreaks[0];
}

int HandValue::get_tb2() {
  return tiebreaks[1];
}

int HandValue::get_tb3() {
  return tiebreaks[2];
}

int HandValue::get_tb4() {
  return tiebreaks[3];
}

int HandValue::get_tb5() {
  return tiebreaks[4];
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

bool HandValue::operator<(const HandValue &right) {
  if (coreValue < right.get_core()) {
    return true;
  } 
  //else if (coreValue == right.get_core()) {
    //TODO: implement
  //} 

  return false;
}

