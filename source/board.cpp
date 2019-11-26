#include "board.h"
#include "card.h"
#include "deck.h"
#include "enums.h"
#include <iostream>
#include <string>


//TODO: right now the board class only deals with a full board. Once this is operational,
//      we will expand to being able to handle flop, turn, river, independently.

int Board::get_num_boardCards() {
  return numBoardCards;
}

Board::Board(Card *first, Card *second, Card *third, Card *fourth, Card *fifth) {
  boardCards[0] = first;
  boardCards[1] = second;
  boardCards[2] = third;
  boardCards[3] = fourth;
  boardCards[4] = fifth;
  numBoardCards = 5;

  suitity[heart] = 0;
  suitity[spade] = 0;
  suitity[diamond] = 0;
  suitity[club] = 0;

  for (int i=0; i<5; ++i) {
    suitity[reverseSuit[boardCards[i]->get_suit()]]++;
  }
}

//Board::Board(Deck *theDeck, Card first, Card second, Card third, Card fourth, Card fifth) {

//
//}

Board::Board(Deck *theDeck) {
  suitity[heart] = 0;
  suitity[spade] = 0;
  suitity[diamond] = 0;
  suitity[club] = 0;

  for (int i=0; i<5; ++i) {
    boardCards[i] = theDeck->draw_card();
    suitity[boardCards[i]->get_suit()]++;
  }
  numBoardCards = 5;
}

void Board::print_board() {
  for (int i=0; i<get_num_boardCards(); ++i) {
    boardCards[i]->print();
  }
}

//returns true if there is a flush between hand and board, false otherwise.
int Board::flush_suit(Card *hand1, Card *hand2) {
  suitity[hand1->get_suit()]++;
  suitity[hand2->get_suit()]++;

  for (int i=0; i<NUM_CARD_SUITS; ++i) {
    if (suitity[i] >= 5) {
      suitity[hand1->get_suit()]--;
      suitity[hand2->get_suit()]--;
      return i;
    }
  }

  suitity[hand1->get_suit()]--;
  suitity[hand2->get_suit()]--;
  return -1;
}

//returns the highest value that is in a straight from the hand and board.
//If no straight exists, returns 0.
int Board::straight_height(Card *hand1, Card *hand2, int suit = -1) {
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

  for (int i=0; i<get_num_boardCards(); ++i) {
    if (boardCards[i]->get_suit() == suit || suit == -1) {
      numArray[boardCards[i]->get_value()]++;
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

int Board::max_pairity(Card *hand1, Card *hand2) {
  int numArray[NUM_CARD_VALUES];
  
  //zeroing numArray
  for (int i=0; i<NUM_CARD_VALUES; ++i) {
    numArray[i] = 0;
  }

  numArray[hand1->get_value()]++;
  numArray[hand2->get_value()]++;

  for (int i=0; i<get_num_boardCards(); ++i) {
    numArray[boardCards[i]->get_value()]++;
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
std::string Board::fullboard_core_value(Card *hand1, Card *hand2) {
  int flush = flush_suit(hand1, hand2);
  int straight = straight_height(hand1, hand2);
  int maxPairity = max_pairity(hand1, hand2);

  if ((flush > -1) && (straight > 0)) {
    if (straight_height(hand1, hand2, flush)) {
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

Board::~Board() {
//  for (int i=0; i<5; ++i) {
//    delete boardCards[i];
//  }
}
