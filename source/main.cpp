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

//  Card *flop1 = new Card(ace, spade);
//  Card *flop2 = new Card(four, spade);
//  Card *flop3 = new Card(three, spade);
//  Card *turn = new Card(two, spade);
//  Card *river = new Card(ten, spade);
//  Card *hand1 = theDeck.draw_card();
//  Card *hand2 = theDeck.draw_card();

  Card *p1c1 = theDeck.draw_card();
  Card *p1c2 = theDeck.draw_card();

  Card *p2c1 = theDeck.draw_card();
  Card *p2c2 = theDeck.draw_card();


//  Card *myCard = theDeck.draw_card();
//  myCard->print();
//  Card *myCard2 = theDeck.draw_card();
//  myCard2->print();
//  Board theBoard(flop1, flop2, flop3, turn, river);
  Board theBoard(theDeck);
  HandValue player1;
  HandValue player2;

  theBoard.print_board();
  cout << "Player 1's Hand: " << p1c1->string_print() << ", " << p1c2->string_print() << endl;
  cout << "Player 2's Hand: " << p2c1->string_print() << ", " << p2c2->string_print() << endl;

  eval.find_handvalue(theBoard, p1c1, p1c2, player1);
  eval.find_handvalue(theBoard, p2c1, p2c2, player2);

  if (player1 < player2) {
    cout << "Player 2 wins!" << endl;
  } else {
    cout << "Player 1 wins!" << endl;
  }
  //TODO: DRAWS?
  cout << "Player 1 had " << handTypes[player1.get_core()] << endl;
  cout << "Player 2 had " << handTypes[player2.get_core()] << endl;
  return 0;

}

