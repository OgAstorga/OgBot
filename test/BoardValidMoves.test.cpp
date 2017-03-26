#include <iostream>

#include "Board.h"

int main() {
  Board b1({
    "xxx.oxoo.",
    ".o.ox.xx.",
    "..ox.x.o.",

    "oox.x....",
    "xxoxox.o.",
    "ooxox.x..",

    ".x...o..o",
    "oooxxx.o.",
    ".x...ooxx",
  });

  vector<short> valid_moves = b1.valid_moves(8*9 + 2);
  if (valid_moves.size() == 4) {
    cout << "pass" << endl;
  } else {
    cout << "fail" << endl;
  }

  valid_moves = b1.valid_moves(8*8 + 8);
  if (valid_moves.size() == 19) {
    cout << "pass" << endl;
  } else {
    cout << "fail" << endl;
  }

  valid_moves = b1.valid_moves(4*9 + 3);
  if (valid_moves.size() == 19) {
    cout << "pass" << endl;
  } else {
    cout << "fail" << endl;
  }

  Board b2({
    "...x.x...",
    "...xox...",
    "...oxo...",

    "....o....",
    ".........",
    ".........",

    ".........",
    ".........",
    ".........",
  });

  valid_moves = b2.valid_moves(4*9 + 1);
  if (valid_moves.size() == 1 && valid_moves[0] == (9*1 + 1)) {
    cout << "pass" << endl;
  } else {
    cout << "fail" << endl;
  }
}
