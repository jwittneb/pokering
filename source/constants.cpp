#include "constants.h"

int RIVER_BET_PERCENT = 80;

//percent of bets that are bluffs
int RIVER_BLUFF_PERCENT = 30;

extern std::vector<RangeEntry> THREES = {RangeEntry(Card(three, club), Card(three, spade)),
                                         RangeEntry(Card(three, club), Card(three, diamond)),
                                         RangeEntry(Card(three, club), Card(three, heart)),
                                         RangeEntry(Card(three, spade), Card(three, diamond)),
                                         RangeEntry(Card(three, spade), Card(three, heart)),
                                         RangeEntry(Card(three, heart), Card(three, diamond))};
