#include "enums.h"
#include "card.h"
#include "deck.h"
#include "board.h"
#include <iostream>

using namespace std;

int main() {

  Card *flop1 = new Card(ten, heart);
  Card *flop2 = new Card(five, spade);
  Card *flop3 = new Card(four, spade);
  Card *turn = new Card(two, spade);
  Card *river = new Card(three, spade);

  Card *hand1 = new Card(nine, spade);
  Card *hand2 = new Card(ace, spade);

  Deck theDeck;
//  Card *myCard = theDeck.draw_card();
//  myCard->print();
//  Card *myCard2 = theDeck.draw_card();
//  myCard2->print();
  Board theBoard(flop1, flop2, flop3, turn, river);
  //Board theBoard(&theDeck);
  theBoard.print_board();
  cout << theBoard.fullboard_core_value(hand1, hand2) << endl;
  return 0;

}

