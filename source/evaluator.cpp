#include "evaluator.h"

void Evaluator::get_suitity(Board &theBoard, const Card *hand1, const Card *hand2) {
  for (int i=0; i<theBoard.get_num_boardcards(); ++i) {
    suitity[theBoard.get_boardcard(i)->get_suit()]++;
  }
  suitity[hand1->get_suit()]++;
  suitity[hand2->get_suit()]++;
}

void Evaluator::reset_suitity() {
  for (int i=0; i<NUM_CARD_SUITS; ++i) {
    suitity[i] = 0;
  }
}

//mutates val to a flush hand if there is a flush between hand and board, makes it an error
//HandValue otherwise.
void Evaluator::flush_hand(Board &theBoard, const Card *hand1, const Card *hand2, HandValue &val) {
  int numArray[NUM_CARD_VALUES];

  for (int i=0; i<NUM_CARD_VALUES; ++i) {
    numArray[i] = 0;
  }
  
  get_suitity(theBoard, hand1, hand2);

  for (int i=0; i<NUM_CARD_SUITS; ++i) {
    if (suitity[i] >= 5) {
      val.set_core(flush);

      for (int j=0; j<theBoard.get_num_boardcards(); ++j) {
        if (theBoard.get_boardcard(i)->get_suit() == i) {
          numArray[theBoard.get_boardcard(i)->get_value()]++;
        }
      }

      int tiebreak = 0;
      for (int j=NUM_CARD_SUITS-1; j>=0; --j) {
        if ((numArray[j] > 0) && (tiebreak <= 4)) {
          val.set_tb(tiebreak, j);
          tiebreak++;
        }
      }
      return;
    }
  }
  reset_suitity();
  val.set_core(error);
  return;
}

//mutates val to a straight HandValue if there is a straight, otherwise mutates it into an error HandValue.
void Evaluator::straight_hand(Board &theBoard, const Card *hand1, const Card *hand2, HandValue &val, int suit = -1) {
  int numArray[NUM_CARD_VALUES];
  
  //zeroing numArray
  for (int i=0; i<NUM_CARD_VALUES; ++i) {
    numArray[i] = 0;
  }

  if (suit == -1 || hand1->get_suit() == suit) {
    numArray[hand1->get_value()]++;
  }
  if (suit == -1 || hand2->get_suit() == suit) {
    numArray[hand2->get_value()]++;
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
  
  //there was a straight if max >= 5
  if (max >= 5) {
    if (suit == -1) {
      val.set_core(straight);
    } else {
      val.set_core(straightflush);
    }
    val.set_tb(0, max);
  } else {
    val.set_core(error);
  }
}

// mutates val to the corresponding HandValue for a pair/set/boat/2pair
void Evaluator::pairity_hand(Board &theBoard, const Card *hand1, const Card *hand2, HandValue &val) {
  int numArray[NUM_CARD_VALUES];
  
  //zeroing numArray
  for (int i=0; i<NUM_CARD_VALUES; ++i) {
    numArray[i] = 0;
  }

  numArray[hand1->get_value()]++;
  numArray[hand2->get_value()]++;

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
      val.set_core(twopair);
      //2pair
    } else {
      val.set_core(onepair);
      //1pair
    }
    return;
  }

  // there is a set, check for boat
  if (max == 3) {
    for (int i=0; i<NUM_CARD_VALUES; ++i) {
      if (numArray[i] == 2) {
        //boat
        val.set_core(boat);
       // for (int j=NUM_CARD_VALUES-1; j>=0; --j) {
       // }
        return;
      } 
    }
    //set
    val.set_core(set);
    return;
  }

  if (max == 4) {
    // 4 of a kind
    val.set_core(fourkind);
    return;
  }

  // else, there is nothing
  int tiebreak = 0;
  val.set_core(nothing);
  for (int i=NUM_CARD_VALUES-1; i>=0; --i) {
    if ((numArray[i] > 0) && (tiebreak < 5)) {
      val.set_tb(tiebreak, i);
      tiebreak++;
    }
  }
}

//input: 2 cards that are in the player's hand, the board, and a HandValue reference that will be
//       mutated to the HandValue corresponding to the board and hand cards.
void Evaluator::find_handvalue(Board &theBoard, const Card *hand1, const Card *hand2, HandValue &val) {
  HandValue temp1;
  HandValue temp2;
  
  flush_hand(theBoard, hand1, hand2, temp1);
  straight_hand(theBoard, hand1, hand2, temp2);
  pairity_hand(theBoard, hand1, hand2, val);

  if ((temp1.get_core() == flush) && (temp2.get_core() == straight)) {
    get_suitity(theBoard, hand1, hand2);
    for (int i=0; i<NUM_CARD_SUITS; ++i) {
      if (suitity[i] >= 5) {
        straight_hand(theBoard, hand1, hand2, temp2, i);
        if (temp2.get_core() == straightflush) {
          val.set_core(straightflush);
        } else {
          val.set_core(flush);
        }
      }
    }
    reset_suitity();
    return;
  } else if (val.get_core() == fourkind) {
    return;
  } else if (val.get_core() == boat) {
    return;
  } else if (temp1.get_core() == flush) {
    val.set_core(flush);
    return;
  } else if (temp2.get_core() == straight) {
    val.set_core(straight);
    return;
  }
}

Evaluator::Evaluator() {
  for (int i=0; i<NUM_CARD_SUITS; ++i) {
    suitity[i] = 0;
  }
}

Evaluator::~Evaluator() {}
