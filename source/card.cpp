#include "card.h"
#include "enums.h"
#include <iostream>

Card::Card(cardValue ivalue, cardSuit isuit) {
  suit = isuit;
  value = ivalue;
}

Card::Card(int ivalue, int isuit) {
  suit = reverseSuit[isuit];
  value = reverseVal[ivalue];
}

void Card::print() {
  std::cout << cardValTypes[value] << " of " << suitTypes[suit] << std::endl;
}

Card::~Card() {}
