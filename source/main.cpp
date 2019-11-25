#include "enums.h"
#include "card.h"
#include "deck.h"
#include "board.h"
#include <iostream>

using namespace std;

int main() {

  Card *flop1 = new Card(jack, heart);
  Card *flop2 = new Card(nine, spade);
  Card *flop3 = new Card(two, spade);
  Card *turn = new Card(two, heart);
  Card *river = new Card(king, diamond);

  Deck theDeck;
//  Card *myCard = theDeck.draw_card();
//  myCard->print();
//  Card *myCard2 = theDeck.draw_card();
//  myCard2->print();
  Board theBoard(flop1, flop2, flop3, turn, river);
  theBoard.print_board();
  return 0;

}

