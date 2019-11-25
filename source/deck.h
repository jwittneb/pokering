#ifndef __DECK_H__
#define __DECK_H__
#include "card.h"
#include <vector>

class Deck {
  std::vector<Card *> deckCards;
  int remainingCards;

  public:
    Deck *get_instance();

    Card *draw_card();
    int get_remaining_cards();

    //TODO: implement
    //void remove_card();

    Deck();
    ~Deck();
};

#endif
