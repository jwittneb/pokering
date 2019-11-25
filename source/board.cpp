#include "board.h"
#include "card.h"
#include "deck.h"
#include <iostream>

Board::Board(Card *first, Card *second, Card *third, Card *fourth, Card *fifth) {
  boardCards[0] = first;
  boardCards[1] = second;
  boardCards[2] = third;
  boardCards[3] = fourth;
  boardCards[4] = fifth;
}

//Board::Board(Deck *theDeck, Card first, Card second, Card third, Card fourth, Card fifth) {

//
//}

Board::Board(Deck *theDeck) {
  for (int i=0; i<5; ++i) {
    boardCards[i] = theDeck->draw_card();
  }
}

void Board::print_board() {
  for (int i=0; i<5; ++i) {
    boardCards[i]->print();
  }
}

Board::~Board() {
//  for (int i=0; i<5; ++i) {
//    delete boardCards[i];
//  }
}
