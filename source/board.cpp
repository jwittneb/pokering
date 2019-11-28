#include "board.h"
#include "card.h"
#include "deck.h"
#include "enums.h"
#include <iostream>
#include <string>


//TODO: right now the board class only deals with a full board. Once this is operational,
//      we will expand to being able to handle flop, turn, river, independently.

int Board::get_num_boardcards() {
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

Card *Board::get_boardcard(int i) {
  assert (i<5);
  return boardCards[i];
}

Board::Board() {
  for (int i=0; i<5; ++i) {
    boardCards[i] = new Card(ace, diamond);
  }
  numBoardCards = 5;
}

Board::Board(Deck &theDeck) {
  for (int i=0; i<5; ++i) {
    boardCards[i] = theDeck.draw_card();
  }
  numBoardCards = 5;
}

void Board::print_board() {
  for (int i=0; i<get_num_boardcards(); ++i) {
    boardCards[i]->print();
  }
}

Board::~Board() {
//  for (int i=0; i<5; ++i) {
//    delete boardCards[i];
//  }
}
