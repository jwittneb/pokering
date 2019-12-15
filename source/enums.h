#ifndef __ENUMS_H__
#define __ENUMS_H__

#include <string>

const int NUM_CARD_VALUES = 13;
const int NUM_CARD_SUITS = 4;

enum cardSuit {
  error = -1,
  club = 0, 
  spade, 
  diamond,
  heart
};

enum cardValue {
  error = -1,
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

enum HandCore {
  error = -1,
  nothing = 0,
  onepair,
  twopair,
  set,
  straight,
  flush,
  boat,
  fourkind,
  straightflush
};

extern std::string suitTypes[NUM_CARD_SUITS];
extern std::string cardValTypes[NUM_CARD_VALUES];
extern std::string handTypes[9];

extern cardValue reverseVal[NUM_CARD_VALUES];
extern cardSuit reverseSuit[NUM_CARD_SUITS];
extern HandCore reverseHand[9];
#endif
