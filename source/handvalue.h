#ifndef __HANDVALUE_H__
#define __HANDVALUE_H__
#include "enums.h"

class HandValue {
  Hand coreValue;
  int tiebreaks[5];

  public:
    void set_core(Hand core);
    void set_tb(int tbindex, int tbval);

    int get_core() const;
    int get_tb1();
    int get_tb2();
    int get_tb3();
    int get_tb4();
    int get_tb5();

    HandValue(Hand core = error, int tb1 = -1, int tb2 = -1, int tb3 = -1, int tb4 = -1, int tb5 = -1);
    ~HandValue();

    bool operator<(const HandValue &right);
};

#endif
