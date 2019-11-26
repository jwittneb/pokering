#include "evaluator.h"

void Evaluator::get_suitity(Board &theBoard, const Card &hand1, const Card &hand2) {
  for (int i=0; i<theBoard.get_num_boardcards(); ++i) {
    suitity[theBoard.get_boardcard(i)->get_suit()]++;
  }
  suitity[hand1.get_suit()]++;
  suitity[hand2.get_suit()]++;
}

void Evaluator::reset_suitity() {
  for (int i=0; i<NUM_CARD_SUITS; ++i) {
    suitity[i] = 0;
  }
}

//returns true if there is a flush between hand and board, false otherwise.
int Evaluator::flush_suit(Board &theBoard, const Card &hand1, const Card &hand2) {
  get_suitity(theBoard, hand1, hand2);

  for (int i=0; i<NUM_CARD_SUITS; ++i) {
    if (suitity[i] >= 5) {
      reset_suitity();
      return i;
    }
  }
  reset_suitity();
  return -1;
}

//returns the highest value that is in a straight from the hand and board.
//If no straight exists, returns 0.
int Evaluator::straight_height(Board &theBoard, const Card &hand1, const Card &hand2, int suit = -1) {
  int numArray[NUM_CARD_VALUES];
  
  //zeroing numArray
  for (int i=0; i<NUM_CARD_VALUES; ++i) {
    numArray[i] = 0;
  }

  if (suit == -1 || hand1.get_suit() == suit) {
    numArray[hand1.get_value()]++;
  }
  if (suit == -1 || hand2.get_suit() == suit) {
    numArray[hand2.get_value()]++;
  }

  for (int i=0; i<theBoard.get_num_boardcards(); ++i) {
    if (theBoard.get_boardcard(i)->get_suit() == suit || suit == -1) {
      numArray[theBoard.get_boardcard(i)->get_value()]++;
    }
  }

  int max = 0;
  //covering the case for Ace to 5 straight
  if ((numArray[12]>0) && (numArray[0]>0) && (numArray[1]>0) && (numArray[2]>0) && (numArray[3]>0)) {
    max = 5;
  }

  //covering the cases for all other straights
  int len = 0;

  for (int i=0; i<NUM_CARD_VALUES; ++i) {
    if ((len >= 4) && (numArray[i] > 0)) {
      max = i+1;
      len++;
    } else if (numArray[i] > 0) {
      len++;
    } else {
      len = 0;
    }
  }
  return max;
}

// returns an int corresponding to the value of the hand
// 0 pair -> 1
// 1 pair -> 2
// set -> 3
// 4 of a kind -> 4
// boat -> 5
// 2 pair -> 6

int Evaluator::max_pairity(Board &theBoard, const Card &hand1, const Card &hand2) {
  int numArray[NUM_CARD_VALUES];
  
  //zeroing numArray
  for (int i=0; i<NUM_CARD_VALUES; ++i) {
    numArray[i] = 0;
  }

  numArray[hand1.get_value()]++;
  numArray[hand2.get_value()]++;

  for (int i=0; i<theBoard.get_num_boardcards(); ++i) {
    numArray[theBoard.get_boardcard(i)->get_value()]++;
  }

  int max = 0;
  for (int i=0; i<NUM_CARD_VALUES; ++i) {
    if (numArray[i] > max) {
      max = numArray[i];
    }
  }

  // there is a pair, check for 2 pairs
  if (max == 2) {
    int numPairs = 0;
    for (int i=0; i<NUM_CARD_VALUES; ++i) {
      if (numArray[i] == 2) {
        numPairs++;
      }
    }
    if (numPairs > 1) {
      return 6;
    } else {
      return 2;
    }
  }

  // there is a set, check for boat
  if (max == 3) {
    for (int i=0; i<NUM_CARD_VALUES; ++i) {
      if (numArray[i] == 2) {
        return 5;
      }
    }
    return 3;
  }

  // else, return max value
  return max;
}

//input: 2 cards that are in the player's hand.
//output: one of the following strings, corresponding to the hand's value:
//        "nothing"
//        "1 pair"
//        "2 pair"
//        "set"
//        "straight"
//        "flush"
//        "boat"
//        "4 of a kind"
//        "straight flush"
//in the event of a tie, another function must be called to determine which is stronger
//TODO: make it so that either this function generalizes to <5 cards on board or make different
//      function for partial board evaluation
std::string Evaluator::core_value(Board &theBoard, const Card &hand1, const Card &hand2) {
  int flush = flush_suit(theBoard, hand1, hand2);
  int straight = straight_height(theBoard, hand1, hand2);
  int maxPairity = max_pairity(theBoard, hand1, hand2);

  if ((flush > -1) && (straight > 0)) {
    if (straight_height(theBoard, hand1, hand2, flush)) {
      return "straight flush";
    }
  } else if (maxPairity == 4) {
    return "4 of a kind";
  } else if (maxPairity == 5) {
    return "boat";
  } else if (flush > -1) {
    return "flush";
  } else if (straight > 0) {
    return "straight";
  } else if (maxPairity == 3) {
    return "set";
  } else if (maxPairity == 6) {
    return "2 pair";
  } else if (maxPairity == 2) {
    return "1 pair";
  } 
  return "nothing";
}

Evaluator::Evaluator() {
  for (int i=0; i<NUM_CARD_SUITS; ++i) {
    suitity[i] = 0;
  }
}

Evaluator::~Evaluator() {}
