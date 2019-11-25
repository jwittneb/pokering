#ifndef __ENUMS_H__
#define __ENUMS_H__

#include <string>

const int NUM_CARD_VALUES = 13;
const int NUM_CARD_SUITS = 4;

enum cardSuit {
  club = 0, 
  spade, 
  diamond,
  heart
};

enum cardValue {
  two = 0,
  three,
  four,
  five,
  six,
  seven,
  eight,
  nine,
  ten,
  jack, 
  queen,
  king, 
  ace
};

extern std::string suitTypes[NUM_CARD_SUITS];
extern std::string cardValTypes[NUM_CARD_VALUES];

extern cardValue reverseVal[NUM_CARD_VALUES];
extern cardSuit reverseSuit[NUM_CARD_SUITS];
#endif
