#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__
#include "range.h"
#include <vector>

//TODO: in position, OOP, previous aggressor?

extern int RIVER_BET_PERCENT;

//percent of bets that are bluffs
extern int RIVER_BLUFF_PERCENT;

//extern Range UTG_;
//extern Range SB_opener;

//standard combinations of range entries
/*
extern vector<RangeEntry> ACES;
extern vector<RangeEntry> KINGS;
extern vector<RangeEntry> QUEENS;
extern vector<RangeEntry> JACKS;
extern vector<RangeEntry> TENS;
extern vector<RangeEntry> NINES;
extern vector<RangeEntry> EIGHTS;
extern vector<RangeEntry> SEVENS;
extern vector<RangeEntry> SIXES;
extern vector<RangeEntry> FIVES;
extern vector<RangeEntry> FOURS;
*/
extern std::vector<RangeEntry> THREES;
/*
extern vector<RangeEntry> TWOS;

extern vector<RangeEntry> ACEKINGS;
extern vector<RangeEntry> ACEQUEENS;
extern vector<RangeEntry> ACEJACKS;
extern vector<RangeEntry> ACETENS;
extern vector<RangeEntry> ACENINES;
extern vector<RangeEntry> ACEEIGHTS;
*/
#endif
