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

std::string Card::string_print() {
  return cardValTypes[value] + " of " + suitTypes[suit];
}

void Card::print() {
  std::cout << cardValTypes[value] << " of " << suitTypes[suit] << std::endl;
}

void Card::set_value(cardValue val) {
  value = val;
}

void Card::set_suit(cardSuit isuit) {
  suit = isuit;
}

Card::Card() {
  //error card, the value and suit should be defined
  suit = error;
  value = error;
}

Card::~Card() {}
