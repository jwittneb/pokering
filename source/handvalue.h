#ifndef __HANDVALUE_H__
#define __HANDVALUE_H__
#include "enums.h"

class HandValue {
  HandCore coreValue;
  int tiebreaks[5];

  public:
    void set_core(HandCore core);
    void set_tb(int tbindex, int tbval);

    int get_core() const;
    int get_tb(int index) const;

    HandValue(HandCore core = error, int tb1 = -1, int tb2 = -1, int tb3 = -1, int tb4 = -1, int tb5 = -1);
    ~HandValue();

    bool operator<(const HandValue &right);
    bool operator==(const HandValue &right);
};

#endif
