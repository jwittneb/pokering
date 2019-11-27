#include "enums.h"
#include "card.h"
#include "deck.h"
#include "board.h"
#include "evaluator.h"
#include <iostream>

using namespace std;

int main() {

  Evaluator eval;
  Deck theDeck;

  Card *flop1 = new Card(five, heart);
  Card *flop2 = new Card(four, spade);
  Card *flop3 = new Card(three, spade);
  Card *turn = new Card(two, spade);
  Card *river = new Card(ace, spade);

  Card *hand1 = theDeck.draw_card();
  Card *hand2 = theDeck.draw_card();


//  Card *myCard = theDeck.draw_card();
//  myCard->print();
//  Card *myCard2 = theDeck.draw_card();
//  myCard2->print();
  Board theBoard(flop1, flop2, flop3, turn, river);
//  Board theBoard(theDeck);
  HandValue test;

  theBoard.print_board();
  hand1->print();
  hand2->print();

  eval.find_handvalue(theBoard, hand1, hand2, test);
  cout << handTypes[test.get_core()] << endl;
  return 0;

}

