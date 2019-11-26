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
    suitity[reverseSuit[boardCards[i]->get_suit()]]++;
  }
  numBoardCards = 5;
}

void Board::print_board() {
  for (int i=0; i<get_num_boardCards(); ++i) {
    boardCards[i]->print();
  }
}

//returns true if there is a flush between hand and board, false otherwise.
bool Board::is_flush(Card *hand1, Card *hand2) {
  suitity[hand1->get_suit()]++;
  suitity[hand2->get_suit()]++;

  for (int i=0; i<NUM_CARD_SUITS; ++i) {
    std::cout << suitity[i] << std::endl;

    if (suitity[i] >= 5) {
      for (int j=0; j<NUM_CARD_SUITS; ++j) {
        suitity[j] = 0;
      }
      return true;
    }
  }

  for (int j=0; j<NUM_CARD_SUITS; ++j) {
    suitity[j] = 0;
  }
  return false;
}

//returns the highest value that is in a straight from the hand and board.
//If no straight exists, returns 0.
int Board::straight_height(Card *hand1, Card *hand2) {
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
  //covering the case for Ace to 5 straight
  if (numArray[12] > 0 && numArray[0] > 0 && numArray[1] > 0 && numArray[2] > 0 && numArray[3] > 0 && numArray[4] > 0) {
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

//input: 2 cards that are in the player's hand.
//output: one of the following strings, corresponding to the hand's value:
//        "nothing"
//        "pair"
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
std::string Board::fullboard_hand_value(Card *hand1, Card *hand2) {
  bool flush = is_flush(hand1, hand2);
  int straight = straight_height(hand1, hand2);
  //int maxParity = max_parity(hand1, hand2);

  if (flush && (straight > 0)) {
    return "straight flush";
 // } else if (maxParity == 4) {
 //   return "4 of a kind";
 // } else if (maxParity == 3) {
 //   if (is_boat(hand1, hand2)) {
 //     return "boat";
 //   }
  } else if (flush) {
    return "flush";
  } else if (straight > 0) {
    return "straight";
 // } else if (maxParity == 3) {
 //   return "set";
 // } else if (maxParity == 2) {
 //   if (num_pairs(hand1, hand2) >= 2) {
 //     return "2 pair";
 //   } else {
 //     return "pair";
 //   }
  } else {
    return "nothing";
  }
}

Board::~Board() {
//  for (int i=0; i<5; ++i) {
//    delete boardCards[i];
//  }
}
