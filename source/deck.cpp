#include "deck.h"
#include "enums.h"
#include "card.h"
#include <chrono>
#include <algorithm>
#include <random>
#include <vector>

int Deck::get_remaining_cards() {
  return remainingCards;
}

Card *Deck::draw_card() {
  assert(remainingCards > 0);
  remainingCards--;
  return deckCards[remainingCards];
}

Deck::Deck() {

  //Put all 52 cards into the deck
  for (int i=0; i<13; ++i) {
    for (int j=0; j<4; ++j) {
      Card *toInsert = new Card(i,j);
      deckCards.push_back(toInsert);
    }
  }
  
  remainingCards = 52;

  // obtain a time-based seed:
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine rng(seed);

  shuffle(deckCards.begin(), deckCards.end(), rng);
}

Deck::~Deck() {
  for (int i=0; i<52; ++i) {
    delete deckCards[i];
  }
}
