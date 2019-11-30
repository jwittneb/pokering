#include "range.h"
#include <vector>
#include <algorithm>
#include <iostream>

RangeEntry Range::get_holding_in_range(int i) {
  return holdingsInRange[i];
}

//creates a range including all possible holecards.
//prevents duplicates such a 9c8s and 8s9c as being separate entries
Range::Range() {
  rangeSize = 0;
  for (int i=0; i<NUM_CARD_SUITS; ++i) {
    for (int j=0; j<NUM_CARD_VALUES; ++j) {
      //suited entries in range
      for (int k=j+1; k<NUM_CARD_VALUES; ++k) {
        holdingsInRange.push_back(RangeEntry(Card(j,i), Card(k,i)));
        rangeSize++;
      }
      
      //offsuit entries in range
      for (int k=i+1; k<NUM_CARD_SUITS; ++k) {
        for (int l=0; l<NUM_CARD_VALUES; ++l) {
          holdingsInRange.push_back(RangeEntry(Card(j,i), Card(l,k)));
          rangeSize++;
        }
      }
    }
  }
}

void Range::sort_range(Evaluator &theEvaluator) {
  std::sort(holdingsInRange.begin(), holdingsInRange.end(), theEvaluator);
}

void Range::cold_bet_range(Evaluator &theEvaluator) {
  int numBluffs = (rangeSize*RIVER_BET_PERCENT*RIVER_BLUFF_PERCENT)/10000;
  int numValueBets = (rangeSize*RIVER_BET_PERCENT*(100-RIVER_BLUFF_PERCENT))/10000;

  sort_range(theEvaluator);
  
  //this is a bit primitive, make it better later
  for (int i=numBluffs; i<rangeSize-numValueBets; ++i) {
    holdingsInRange[i] = holdingsInRange.back();
    holdingsInRange.pop_back();
  }

  rangeSize = numBluffs + numValueBets;
  sort_range(theEvaluator);
}


void Range::remove_from_range(Card &toRemove) {
  //does not maintain order
  int end=rangeSize-1;
  for (int i=end; i>=0 ; --i) {
    if (((holdingsInRange[i].get_card1()->get_value() == toRemove.get_value()) &&
         (holdingsInRange[i].get_card1()->get_suit() == toRemove.get_suit())) ||
        ((holdingsInRange[i].get_card2()->get_value() == toRemove.get_value()) &&
          (holdingsInRange[i].get_card2()->get_suit() == toRemove.get_suit()))) {
      holdingsInRange[i] = holdingsInRange.back();
      holdingsInRange.pop_back();
      rangeSize--;
    }
  }
}

Range::Range(std::vector<RangeEntry> holdings) {
  holdingsInRange = holdings;
  rangeSize = holdings.size();
}

int Range::get_rangesize() {
  return rangeSize;
}

Range::~Range() {}
