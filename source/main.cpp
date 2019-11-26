#include "enums.h"
#include "card.h"
#include "deck.h"
#include "board.h"
#include <iostream>

using namespace std;

int main() {

  Card *flop1 = new Card(jack, heart);
  Card *flop2 = new Card(nine, heart);
  Card *flop3 = new Card(two, spade);
  Card *turn = new Card(two, heart);
  Card *river = new Card(king, diamond);

  Card *hand1 = new Card(nine, spade);
  Card *hand2 = new Card(queen, spade);

  Deck theDeck;
//  Card *myCard = theDeck.draw_card();
//  myCard->print();
//  Card *myCard2 = theDeck.draw_card();
//  myCard2->print();
  Board theBoard(&theDeck);
  theBoard.print_board();
  cout << theBoard.fullboard_hand_value(hand1, hand2) << endl;
  return 0;

}

