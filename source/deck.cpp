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

//This function is used when we want specific hole cards/board cards
void Deck::remove_card(Card toRemove) {
  for (int i=0; i<deckCards.size(); ++i) {
    if ((deckCards[i]->get_value() == toRemove.get_value()) &&
        (deckCards[i]->get_suit() == toRemove.get_suit())) {
      deckCards.erase(deckCards.begin() + i);
    }
  }
}

Deck::Deck() {

  //Put all 52 cards into the deck
  for (int i=0; i<NUM_CARD_VALUES; ++i) {
    for (int j=0; j<NUM_CARD_SUITS; ++j) {
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
