#include <iostream>
#include <time.h>

#include "Board.h"

int main() {
  Board b1({
    "ooo......",
    ".........",
    ".........",

    ".........",
    ".........",
    ".........",

    ".........",
    ".........",
    ".........",
  });

  pair<short, short> macro = b1.macro_board();

  if (macro.first == 1 && macro.second == 0) {
    cout << "pass" << endl;
  } else {
    cout << "fail" <<endl;
  }

  Board b2({
    ".........",
    ".........",
    ".........",

    ".........",
    ".........",
    ".........",

    ".........",
    ".........",
    "......xxx",
  });

  macro = b2.macro_board();

  if (macro.first == 0 && macro.second == 256) {
    cout << "pass" << endl;
  } else {
    cout << "fail" <<endl;
  }

  Board b3({
    "xxx.oxoo.",
    ".o.ox.xxx",
    "..ox.x.o.",

    "o.x.x....",
    "xxoxox.o.",
    "ooxox.x..",

    ".x...o..o",
    "oooxxx.o.",
    ".x...ooxx",
  });

  macro = b3.macro_board();
  if (b3.quadrant_won(macro.first) == false && b3.quadrant_won(macro.second) == true) {
    cout << "pass" << endl;
  } else {
    cout << "fail" <<endl;
  }
}
