#include "enums.h"
#include "card.h"
#include "deck.h"
#include "board.h"
#include "evaluator.h"
#include "range.h"
#include "rangeentry.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  Deck theDeck;

  //Card *flop1 = theDeck.draw_card();
  //Card *flop2 = theDeck.draw_card();
  //Card *flop3 = theDeck.draw_card();
  //Card *turn = theDeck.draw_card();
  //Card *river = theDeck.draw_card();

  Card *flop1 = new Card(ace, diamond);
  Card *flop2 = new Card(eight, club);
  Card *flop3 = new Card(ace, spade);
  Card *turn = new Card(king, diamond);
  Card *river = new Card(four, diamond);

  Board *theBoard = new Board(flop1, flop2, flop3, turn, river);
  
  //RangeEntry entry1(Card(nine, club), Card(jack, club));
  //RangeEntry entry2(Card(king, club), Card(six, spade));
  //RangeEntry entry3(Card(two, club), Card(ten, diamond));
  //RangeEntry entry4(Card(nine,club), Card(nine, diamond));
  //vector<RangeEntry> entries;
  //entries.push_back(entry1);
  //entries.push_back(entry2);
  //entries.push_back(entry3);
  //entries.push_back(entry4);

 // Range theRange(entries);
  Range theRange;

  theRange.remove_from_range(*flop1);
  theRange.remove_from_range(*flop2);
  theRange.remove_from_range(*flop3);
  theRange.remove_from_range(*turn);
  theRange.remove_from_range(*river);
  

  Evaluator theEvaluator(theBoard);
  theRange.sort_range(theEvaluator);

  for (int i=0; i<theRange.get_rangesize(); ++i) {
    RangeEntry temp = theRange.get_holding_in_range(i);
    cout << temp.get_card1()->string_print() << "+" << temp.get_card2()->string_print() << endl;
  }

  theBoard->print_board();


/* CARD TESTING

  Card *flop1 = new Card(nine, heart);
  Card *flop2 = new Card(ace, club);
  Card *flop3 = new Card(ten, heart);
  Card *turn = new Card(jack, spade);
  Card *river = new Card(queen, spade);
*//*
  Card *p1c1 = new Card(six, diamond);
  Card *p1c2 = new Card(king, diamond);

  Card *p2c1 = new Card(seven, diamond);
  Card *p2c2 = new Card(five, heart);
*/
/*
  Card *p1c1 = new Card(nine, club);
  Card *p1c2 = new Card(jack, club);

  Card *p2c1 = new Card(king, club);
  Card *p2c2 = new Card(six, spade);
*/

//  Card *myCard = theDeck.draw_card();
//  myCard->print();
//  Card *myCard2 = theDeck.draw_card();
//  myCard2->print();
//  Board theBoard(flop1, flop2, flop3, turn, river);
// Board theBoard(theDeck);
/*
  Evaluator theEvaluator(theBoard);
  HandValue player1;
  HandValue player2;

  theBoard->print_board();
  cout << "Player 1's Hand: " << p1c1->string_print() << ", " << p1c2->string_print() << endl;
  cout << "Player 2's Hand: " << p2c1->string_print() << ", " << p2c2->string_print() << endl;

  theEvaluator.find_handvalue(theBoard, p1c1, p1c2, player1);
  theEvaluator.find_handvalue(theBoard, p2c1, p2c2, player2);

  if (player1 < player2) {
    cout << "Player 2 wins!" << endl;
  } else if (player1 == player2) {
    cout << "draw!" << endl;
  } else {
    cout << "Player 1 wins!" << endl;
  }
  cout << "Player 1 had " << handTypes[player1.get_core()] << "! tiebreak: " << player1.get_tb(4)+2 << endl;
  cout << "Player 2 had " << handTypes[player2.get_core()] << "! tiebreak: " << player2.get_tb(4)+2 << endl;
  cout << (player2 < player1) << endl;
  */
  return 0;

}

